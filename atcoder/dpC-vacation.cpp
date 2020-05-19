#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

const int NMAX = 1e5 + 11;

int  n, abc[NMAX][3], mem[NMAX][3];
bool vis[NMAX][3];

// i : current pos, p : prev option
int dp(int i, int p)
{
    int &ans = mem[i][p];

    if (i == n)
        return 0;
    if (vis[i][p])
        return mem[i][p];
    vis[i][p] = true;

    ans = INT_MIN;
    for (int j = 0; j < 3; ++j)
    {
        if (j == p)
            continue;
        ans = max(ans, dp(i + 1, j) + abc[i][j]);
    }

    return ans;
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> abc[i][j];

    cout << dp(0, -1) << endl;

    return 0;
}
