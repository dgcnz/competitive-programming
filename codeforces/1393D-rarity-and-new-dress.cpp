#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vector<string> const &grid)
{
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 1));
    int                 ans = m + 2 * (n - 1);
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = m - 2; j >= 1; --j)
        {
            if (grid[i][j] == grid[i + 1][j - 1] and
                grid[i][j] == grid[i + 1][j] and
                grid[i][j] == grid[i + 1][j + 1])
            {
                dp[i][j] =
                    min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]}) + 1;
                int k = i + 2 * (dp[i][j] - 1);
                if (not(k < n and grid[i][j] == grid[k][j]))
                    dp[i][j]--;
            }
            ans += dp[i][j];
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
    read(all(grid));

    cout << solve(grid) << endl;
    return 0;
}
