#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/multidimensional>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vector<vi> a, int Y, int K)
{
    int       M = a.size(), X = a.back().size();
    int const INF = 1e9;
    auto      dp  = create_multidimensional(M, X, Y + 1, K + 1, -INF);

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            for (int y = 0; y <= Y; ++y)
            {
                // fill(all(dp[i][j][0]), 0);
                for (int k = 0; k <= K; ++k)
                {
                    auto &ans = dp[i][j][y][k];
                    if (y == 0) // can't choose
                    {
                        if (j > 0) // skip current, go left
                            ans = dp[i][j - 1][y][K];
                        else if (j == 0 and i > 0)
                            ans = dp[i - 1][X - 1][Y][K]; // skip current go up
                        else                              // i == 0 j == 0
                            ans = 0;
                    }
                    else if (k == 0) // can't choose
                    {
                        if (j > 0) // skip current, go left
                            ans = dp[i][j - 1][y][K];
                        else if (j == 0 and i > 0 and y == 0)
                            ans = dp[i - 1][X - 1][Y][K]; // skip current go up
                        else if (j == 0 and i >= 0 and y > 0)
                            ans = -INF;
                        else // i == 0 j == 0
                            ans = 0;
                    }
                    else if (i == 0 and j == 0)
                    {
                        if (y == 1)
                            ans = a[i][j];
                    }
                    else if (j > 0)
                    {
                        ans = dp[i][j - 1][y][K];
                        if (dp[i][j - 1][y - 1][k - 1] != -INF)
                            ans =
                                max(ans, dp[i][j - 1][y - 1][k - 1] + a[i][j]);
                    }
                    else if (y == 1 and dp[i - 1][X - 1][Y][k - 1] != -INF)
                    {
                        ans = dp[i - 1][X - 1][Y][k - 1] + a[i][j];
                    }
                }
            }
        }
    }
    auto ans = dp[M - 1][X - 1][Y][K];
    if (ans == -INF)
        return -1;
    else
        return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int m, x, y, k;
        cin >> m >> x >> y >> k;

        vector<vi> a(m, vi(x));
        for (int i = 0; i < m; ++i)
            read(all(a[i]));

        auto ans = solve(a, y, k);
        if (ans == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
