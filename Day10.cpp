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
vector<vi> board;
int n, m;
ll ans1 = 0, ans2 = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool inside(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    return false;
}

void solve(int i, int j, int val, set<pii> &s, bool part1)
{
    if (!inside(i, j))
        return;
    if (part1)
    {
        if (s.count({i, j}))
            return;
        s.insert({i, j});
    }
    // cout << board[i][j] << "::" <<  i << " " << j << " " << sx << " " << sy << "\n" ;
    if (val == 9)
    {
        // cout << "YAY\n";
        if(part1)
            ans1++;
        else
            ans2++;
        return;
    }
    for (int t = 0; t < 4; t++)
    {
        int nx = i + dx[t];
        int ny = j + dy[t];
        if (inside(nx, ny))
        {
            if (board[nx][ny] == (board[i][j] + 1))
                solve(nx, ny, board[nx][ny], s, part1);
        }
    }
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        vi temp;
        for (int i = 0; i < s.size(); i++)
            temp.push_back(s[i] - '0');
        board.push_back(temp);
    }
    n = board.size(), m = board[0].size();

    // ------------------ Part1 ---------------------
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0)
            {
                set<pii> s;
                solve(i, j, 0, s, true);
            }
    }
    cout << ans1 << "\n";

    // --------------- Part2 --------------------------
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0)
            {
                set<pii> s;
                solve(i, j, 0, s, false);
            }
    }
    cout << ans2 << "\n";

    return 0;
}
