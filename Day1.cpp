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
    string s;
    vll a, b;
    map<ll, ll> ma,mb;
    while (getline(cin, s))
    {
        vector<string> ans = tokenize(s);
        a.push_back(stoll(ans[0]));
        b.push_back(stoll(ans[1]));
    }
    sort(all(a));
    sort(all(b));
    ll ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ans += abs(a[i] - b[i]);
        ma[a[i]]++;
        mb[b[i]]++;
    }
    ll ans2 = 0;

    for (auto x : ma)
    {
        if(mb.find(x.first) != mb.end())
            ans2 += x.second *mb[x.first]*x.first;
    }
    cout << ans << "\n"
         << ans2 << "\n";
    return 0;
}
