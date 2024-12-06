#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<string> tokenize(string &str, char delimiter)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int main()
{
    string s;
    map<int, set<int>> rules;
    while (getline(cin, s))
    {
        if (s == "")
            break;
        vector<string> parse = tokenize(s, '|');
        assert(parse.size() == 2);
        rules[stoi(parse[0])].insert(stoi(parse[1]));
    }
    vector<vi> updates;
    while (getline(cin, s))
    {
        vector<int> temp;
        vector<string> parse = tokenize(s, ',');
        for (int i = 0; i < parse.size(); i++)
            temp.push_back(stoi(parse[i]));
        updates.push_back(temp);
    }

    vector<vi> incorrect;
    // PART1
    ll ans = 0;
    for(int i=0;i<updates.size();i++)
    {
        bool correct = true;
        for(int j=updates[i].size()-1; j>=0; j--)
        {
            for(int k = j-1;k>=0;k--)
            {
                if(rules[updates[i][j]].find(updates[i][k]) != rules[updates[i][j]].end())
                {
                    incorrect.push_back(updates[i]);
                    correct = false;
                    break;
                }
            }
            if(!correct)
                break;
        }
        if(correct)
            ans += updates[i][updates[i].size()/2];
    }    
    cout << ans << "\n";
    // Part 2
    ll ans2 = 0;
    for(int i=0;i<incorrect.size();i++)
    {
        for(int j=incorrect[i].size()-1; j>=0; j--)
        {
            for(int k = j-1;k>=0;k--)
            {
                if(rules[incorrect[i][j]].find(incorrect[i][k]) != rules[incorrect[i][j]].end())
                {
                    swap(incorrect[i][j], incorrect[i][k]);
                }
            }
            
        }
        ans2 += incorrect[i][incorrect[i].size()/2];
    } 
    cout << ans2 << "\n";   
    
    return 0;
}
