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

vector<string> board;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

string YAY = "XMAS", YAY2 = "MAS";
ll ans = 0;

bool inside(int i, int j)
{
    if (i >= 0 && i < board.size() && j >= 0 && j < board[i].size())
        return true;
    return false;
}

vector<string> create;
void check(char ch, int pos, int i, int j, int dirx, int diry)
{
    if (pos == 3)
    {
        if (ch == 'S')
        {
            for (int k = 0; k < 4; k++)
            {
                create[i][j] = board[i][j];
                i -= dirx;
                j -= diry;
            }
            ans++;
        }
        return;
    }
    if (ch != YAY[pos] )
        return;
    if (!inside(i + dirx, j + diry))
        return;
    // cout << i << " " << j << " " << nx << " " << ny << " " << board[nx][ny] << "\n";
    check(board[i + dirx][j + diry], pos + 1, i + dirx, j + diry, dirx, diry);
    return;
}

map<pii, vector<pii>> m;
void check2(char ch, int pos, int i, int j, int dirx, int diry)
{
    if (pos == 2)
    {
        if (ch == 'S')
        {
            pii e1 = {i,j}, e2 = {i-2*dirx, j-2*diry};
            m[{i-dirx, j-diry}].push_back(e1); 
            m[{i-dirx, j-diry}].push_back(e2); 
        }
        return;
    }
    if (ch != YAY2[pos])
        return;
    if (!inside(i + dirx, j + diry))
        return;
    // cout << i << " " << j << " " << nx << " " << ny << " " << board[nx][ny] << "\n";
    check2(board[i + dirx][j + diry], pos + 1, i + dirx, j + diry, dirx, diry);
    return;
}


int main()
{
    string s;
    while (getline(cin, s))
        board.push_back(s);
    vector<string> empty(board.size(), string(board[0].size(), '.'));
    create = empty;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            for (int t = 0; t < 8; t++)
            {
                int dirx = dx[t], diry = dy[t];
                check(board[i][j], 0, i, j, dirx, diry);
            }
        }
    }
    // for(auto x : create)
    //     cout << x << "\n";

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            for (int t = 1; t < 8; t+=2)
            {
                int dirx = dx[t], diry = dy[t];
                check2(board[i][j], 0, i, j, dirx, diry);
            }
        }
    }

    ll ans2 = 0;
    for(auto x : m)
    {
        if(x.second.size() == 4)
            ans2++;  // X exists
    }
    cout << "-------------------------\n";
    cout << ans << " " << ans2;
    return 0;
}
