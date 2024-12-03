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

vector<string> tokenize(string &str)
{
    vector<string> tokens;
    istringstream stream(str);
    string token;

    while (stream >> token)
    {
        tokens.push_back(token);
    }

    return tokens;
}
int main()
{
    string input;
    string s;
    while(getline(cin, s)){
        input +=s;
    }
    ll sum = 0;
    ll sum2 = 0;
    bool pos = true;
    for (int i = 0; i < input.size(); ++i) {
        if(input.substr(i,4) == "do()")
            pos = true;
        else if(input.substr(i,7) == "don't()")
            pos = false;
        if (input.substr(i, 4) == "mul(") {
            int j = i + 4;
            int num1 = 0, num2 = 0;
            bool valid = true;
            while (j < input.size() && isdigit(input[j])) {
                num1 = num1 * 10 + (input[j] - '0');
                j++;
            }
            if (j >= input.size() || input[j] != ',') {
                valid = false;
            } else {
                ++j; 
            }
            while (j < input.size() && isdigit(input[j])) {
                num2 = num2 * 10 + (input[j] - '0');
                ++j;
            }
            if (j >= input.size() || input[j] != ')') {
                valid = false;
            }
            if (valid) {
                sum += num1 * num2;
                if(pos)
                    sum2 += num1*num2;
            }
            i = j;
        }
    }

   cout << sum << " " << sum2 << '\n';
    return 0;
}
