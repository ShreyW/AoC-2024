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

int main()
{
    // setIO("input");
    string s;
    getline(cin, s);
    int parity = 0;
    int id = 0;
    vector<int> v;
    vector<pair<pii, int>> m;
    int loc = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2)
        {
            int val = s[i] - '0';
            for (int j = 0; j < val; j++)
                v.push_back(-1);
            m.push_back({{loc, -1}, val});
            loc += val;
        }
        else
        {
            int val = s[i] - '0';
            for (int j = 0; j < val; j++)
                v.push_back(id);
            m.push_back({{loc, id}, val});
            id++;
            loc += val;
        }
    }
    // for (auto x : m)
    //     cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
    // for (auto x : v)
    //     cout << x << " ";
    // cout << '\n';
    // ------------------ Part 1 ----------------------------
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        if (v[j] == -1)
            j--;
        else if (v[i] != -1)
            i++;
        else
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    ll checksum1 = 0;
    for (int t = 0; t < v.size(); t++)
    {
        if (v[t] == -1)
            break;
        int val = v[t];
        checksum1 += t * val;
    }
    cout << checksum1 << "\n";
    // ----------------------Part 2 ---------------------------
    for (int i = m.size() - 1; i >= 0; i--)
    {
        if (m[i].first.second == -1)
            continue;
        else
        {
            int space = m[i].second;
            for (int j = 0; j < i; j++)
            {
                if (m[j].first.second == -1)
                {
                    int available = m[j].second;
                    if (available >= space)
                    {
                        m.push_back({{m[i].first.first, -1}, m[i].second});
                        // cout << m[i].first.first << "::::"<< m[i].first.second << " " << m[i].second << "\n";
                        m[i].first.first = m[j].first.first;
                        m[j].first.first += m[i].second;
                        m[j].second -= m[i].second;
                        break;
                    }
                    else
                        continue;
                }
            }
        }
    }
    sort(all(m));
    // cout << "AFTER------------\n";
    // for (auto x : m)
    //     cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
    vector<int> ans2;
    for (int i = 0; i < m.size(); i++)
    {
        int times = m[i].second;
        for (int j = 0; j < times; j++)
        {
            ans2.push_back(m[i].first.second);
        }
    }
    ll checksum2 = 0;
    for (int t = 0; t < ans2.size(); t++)
    {
        if (ans2[t] != -1)
            checksum2 += t * ans2[t];
    }
    cout << checksum2 << "\n";

    return 0;
}
