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
vector<string> ans;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
pii guard_pos;

bool simulate(pii obs)
{
    set<tuple<int, int, int>> states;
    int x = guard_pos.first, y = guard_pos.second, dir = 0;
    while (true)
    {
        if (states.count({x, y, dir}))
            return true;
        states.insert({x, y, dir});
        int nx = x + dx[dir], ny = y + dy[dir];
        // cout << x << ":" << y << ":" << grid[x][y] << ":" << nx << ":" << ny << "\n";
        if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
            return false;
        if (pii{nx, ny} == obs || grid[nx][ny] == '#')
        {
            dir = (dir + 1) % 4;
            continue;
        }
        x = nx;
        y = ny;
    }
}
int main()
{
    // setIO("input");
    string s;
    while (getline(cin, s))
    {
        grid.push_back(s);
    }
    ans = grid;
    n = grid.size();
    m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (grid[i][j] == '^')
            {
                guard_pos = {i, j};
                ans[i][j] = 'X';
            }
    }
    int x = guard_pos.first, y = guard_pos.second;
    int dir = 0;
    while (true)
    {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
        {
            ans[x][y] = 'X';
            break;
        }
        if (grid[nx][ny] == '#')
        {
            dir = (dir + 1) % 4;
            continue;
        }
        ans[nx][ny] = 'X';
        // cout << x << ":" << y << ":" << grid[x][y]  << ":" << nx << ":" << ny  << "\n";
        x = nx;
        y = ny;
    }
    ll p1 = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << ans[i][j];
            if (ans[i][j] == 'X')
                p1++;
        }
        // cout << "\n";
    }
    cout << p1 << "\n";
    // Part 2
    int obs = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == 'X' && (i != guard_pos.first || j != guard_pos.second))
            {
                
                if (simulate({i, j}))
                {
                    obs++;
                }
            }
        }
    }
    cout << obs << "\n";

    return 0;
}
