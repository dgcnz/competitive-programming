#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vector<string> grid)
{
    int n = grid.size(), m = grid[0].size();

    int        ans = 1;
    vector<vi> dp(n, vi(m, 1));
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = m - 2; j >= 0; --j)
        {
            if (grid[i][j] != grid[i][j + 1] or
                grid[i + 1][j] != grid[i + 1][j + 1])
                continue;

            dp[i][j] = min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]}) + 1;
            ans      = max(ans, dp[i][j] * dp[i][j]);
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &row : grid)
        cin >> row;

    cout << solve(grid) << endl;
    return 0;
}
