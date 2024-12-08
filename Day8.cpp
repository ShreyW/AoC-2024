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

vector<string> grid;
map<char, vii> keys;
vector<string> ans1;

bool check(pii p, int n, int m)
{
    if (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m)
        return true;
    return false;
}
int antinode1()
{
    int n = grid.size(), m = grid[0].size();
    set<pii> locations;
    for (auto x : keys)
    {
        for (int i = 0; i < x.second.size(); i++)
        {
            for (auto j = i + 1; j < x.second.size(); j++)
            {
                pii pos1 = {2 * x.second[i].first - x.second[j].first, 2 * x.second[i].second - x.second[j].second};
                if (check(pos1, n, m))
                {
                    ans1[pos1.first][pos1.second] = '#';
                    locations.insert(pos1);
                }
                pii pos2 = {2 * x.second[j].first - x.second[i].first, 2 * x.second[j].second - x.second[i].second};
                if (check(pos2, n, m))
                {
                    ans1[pos2.first][pos2.second] = '#';
                    locations.insert(pos2);
                }
            }
        }
    }
    return locations.size();
}
int antinode2()
{
    int n = grid.size(), m = grid[0].size();
    set<pii> locations;
    for (auto x : keys)
    {
        for (int i = 0; i < x.second.size(); i++)
        {
            for (auto j = i + 1; j < x.second.size(); j++)
            {
                pii midpoint = x.second[i];
                pii down = x.second[j];
                locations.insert(down);
                while (true)
                {
                    pii upper = {2 * midpoint.first - down.first, 2 * midpoint.second - down.second};
                    if (check(upper, n, m))
                    {
                        ans1[upper.first][upper.second] = '#';
                        locations.insert(upper);

                    }
                    else
                    {
                        break;
                    }
                    down = midpoint;
                    midpoint = upper;
                }
                pii upper = x.second[i];
                midpoint = x.second[j];
                locations.insert(upper);
                while (true)
                {
                    pii down = {2 * midpoint.first - upper.first, 2 * midpoint.second - upper.second};
                    if (check(down, n, m))
                    {
                        ans1[down.first][down.second] = '#';
                        locations.insert(down);
                    }
                    else
                    {
                        break;
                    }
                    upper = midpoint;
                    midpoint = down;
                }
            }
        }
    }
    return locations.size();
}
int main()
{
    string s;

    while (getline(cin, s))
    {
        grid.push_back(s);
        ans1.push_back(s);
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] != '.')
            {
                keys[grid[i][j]].push_back({i, j});
            }
        }
    }
    cout << antinode1() << "\n";
    cout << antinode2() << "\n";
    // for (auto x : ans1)
    // {
    //     cout << x << "\n";
    // }
    // for(auto x : keys)
    //     for(auto y: x.second)
    //         cout << x.first << ":" << y.first << " "  << y.second << "\n";
    return 0;
}
