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
    // setIO("input");
    string s;
    multiset<ll> st;
    map<ll, ll> m;
    while (cin >> s)
    {
        if (s == "$")
            break;
        st.insert(stoll(s));
        m[stoll(s)]++;
    }
    // vector<string> parse = tokenize(s, ' ');
    // for (int i = 0; i < parse.size(); i++)
    //     st.insert(stoll(parse[i]));
    // ------------ Part1 --------------
    int iter = 25;
    for (int i = 0; i < iter; i++)
    {
        vector<ll> to_remove;
        vector<ll> to_add;
        for (auto x : st)
        {
            string temp = to_string(x);
            if (x == 0LL)
            {
                to_add.push_back(1);
            }
            else if (temp.size() % 2 == 0)
            {
                string s1 = temp.substr(0, temp.size() / 2);
                string s2 = temp.substr(temp.size() / 2, temp.size() / 2);
                assert((s1 + s2) == temp);

                to_add.push_back(stoll(s1));
                to_add.push_back(stoll(s2));
            }
            else
            {
                to_add.push_back((ll)(2024 * x));
            }
            to_remove.push_back(x);
        }
        for (ll x : to_remove)
            st.erase(st.find(x));
        for (ll x : to_add)
            st.insert(x);
        // for (auto x : st)
        //     cout << x << " ";
        // cout << "\n";
        cout << i + 1 << " " << st.size() << "\n";
    }
    // ------------ Part2 ----------------
    int iter2 = 75;
    for (int i = 0; i < iter2; i++)
    {
        map<ll, ll> new_map;
        for (auto x : m)
        {
            string temp = to_string(x.first);
            if (x.first == 0LL)
            {
                new_map[1] += x.second;
            }
            else if (temp.size() % 2 == 0)
            {
                string s1 = temp.substr(0, temp.size() / 2);
                string s2 = temp.substr(temp.size() / 2, temp.size() / 2);
                assert((s1 + s2) == temp);
                new_map[stoll(s1)] += x.second;
                new_map[stoll(s2)] += x.second;
            }
            else
            {
                new_map[(2024 * x.first)] += x.second;
            }
        }
        m = new_map;

        // for (auto x : new_map)
        //     cout << x.first << ":" << x.second << " -- ";
        // cout << "\n";
        ll ans2 = 0;
        for (auto x : m)
            ans2 += x.second;
        cout << i + 1 << " " << ans2 << "\n";
    }
    // for (auto x : m)
    //     ans2 += x.second;
    // cout << ans2 << "\n";
    return 0;
}
