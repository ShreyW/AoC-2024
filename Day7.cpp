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

vector<vll> nums;
vector<string> process(string s)
{
    stringstream ss(s);
    vector<string> tokens;
    string token;
    while (ss >> token)
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool pos(ll target, ll sum, int line, int idx, int op)
{
    if (idx == nums[line].size())
    {
        // cout << sum << " " << line << ":" << op << " " << target << "\n";
        if (sum == target)
            return true;
        return false;
    }
    if (op == 0)
    {
        return pos(target, sum + nums[line][idx], line, idx + 1, 0) | pos(target, sum + nums[line][idx], line, idx + 1, 1);
    }
    else
    {
        return pos(target, sum * nums[line][idx], line, idx + 1, 0) | pos(target, sum * nums[line][idx], line, idx + 1, 1);
    }
}

bool pos2(ll target, ll sum, int line, int idx, int op)
{
    if (idx == nums[line].size())
    {
        // cout << sum << " " << line << ":" << op << " " << target << "\n";
        if (sum == target)
            return true;
        return false;
    }
    if (op == 0)
    {
        bool c1 = pos2(target, sum + nums[line][idx], line, idx + 1, 0);
        bool c2 = pos2(target, sum + nums[line][idx], line, idx + 1, 1);
        bool c3 = pos2(target, sum + nums[line][idx], line, idx + 1, 2);
        return c1 | c2 | c3;
    }
    else if (op == 1)
    {
        bool c1 = pos2(target, sum * nums[line][idx], line, idx + 1, 0);
        bool c2 = pos2(target, sum * nums[line][idx], line, idx + 1, 1);
        bool c3 = pos2(target, sum * nums[line][idx], line, idx + 1, 2);
        return c1 | c2 | c3;
    }
    else
    {
        string s = to_string(sum);
        string s1 = to_string(nums[line][idx]);
        s = s + s1;
        bool c1 = pos2(target, stoll(s), line, idx + 1, 0);
        bool c2 = pos2(target, stoll(s), line, idx + 1, 1);
        bool c3 = pos2(target, stoll(s), line, idx + 1, 2);
        return c1 | c2 | c3;
    }
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        if(s == "$")
            break;
        vector<string> tokens = process(s);
        vll temp;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (i == 0)
            {
                tokens[i] = tokens[i].substr(0, tokens[i].size() - 1);
                temp.push_back(stoll(tokens[i]));
                continue;
            }
            temp.push_back(stoll(tokens[i]));
        }
        nums.push_back(temp);
    }
    // for (auto x : nums)
    // {
    //     for (auto y : x)
    //         cout << y << " ";
    //     cout << "\n";
    // }
    // Part 1:
    ll ans1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (pos(nums[i][0], 0, i, 1, 0) || pos(nums[i][0], 0, i, 1, 1))
            ans1 += nums[i][0];
    }
    cout << ans1 << "\n";
    // Part 2:
    ll ans2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (pos2(nums[i][0], 0, i, 1, 0) || pos2(nums[i][0], 0, i, 1, 1) || pos2(nums[i][0], 0, i, 1, 2))
            ans2 += nums[i][0];
    }
    cout << ans2 << "\n";
    return 0;
}
