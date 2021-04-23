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
using vi = vector<ll>;

vector<vi> solve(int n, int m, int K, vector<vi> wr, vector<vi> wd)
{
    if (K % 2)
        return vector<vi>(n, vi(m, -1));
    K /= 2;

    ll const           INF = 1e16; // check
    vector<vector<vi>> dp(K + 1, vector<vi>(n, vi(m, INF)));
    auto               in_bounds = [n, m](int i, int j) {
        return 0 <= i and i < n and 0 <= j and j < m;
    };

    for (int k = 0; k <= K; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                auto &ans = dp[k][i][j];
                if (k == 0)
                    ans = 0;
                else
                {
                    if (in_bounds(i - 1, j)) // up
                        ans = min(ans, dp[k - 1][i - 1][j] + 2 * wd[i - 1][j]);
                    if (in_bounds(i, j - 1)) // left
                        ans = min(ans, dp[k - 1][i][j - 1] + 2 * wr[i][j - 1]);
                    if (in_bounds(i + 1, j)) // down
                        ans = min(ans, dp[k - 1][i + 1][j] + 2 * wd[i][j]);
                    if (in_bounds(i, j + 1)) // right
                        ans = min(ans, dp[k - 1][i][j + 1] + 2 * wr[i][j]);
                }
            }
        }
    }

    return dp[K];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> wr(n, vi(m - 1));
    for (auto &wri : wr)
        read(all(wri));

    vector<vi> wd(n - 1, vi(m));
    for (auto &wdi : wd)
        read(all(wdi));
    auto ans = solve(n, m, k, wr, wd);
    for (auto &row : ans)
        write(all(row), " "), cout << endl;
    return 0;
}
