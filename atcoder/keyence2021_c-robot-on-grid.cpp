/** @file
 * @date                2021-01-16
 * @url https://atcoder.jp/contests/keyence2021/tasks/keyence2021_c
 * @tags                dp
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         30
 * @time_complexity     O(n^2)
 * @memory_complexity   O(n^2)
 * @idea
 * Observations:
 * - 1. For a given valid path that filled $x$ empty cells, one has $3^{k - x}$
 * possible configurations (one can freely permute the empty cells that were not
 * used in a valid path).
 * -
 *
 * Let's define $rowcnt_i(j1, j2)$ to be the amount of empty cells in the range
 * $(i, j1), (i, j1 + 1), ..., (i, j2)$. Similarly, define $colcnt_j(i1, i2)$ as
 * the amount of empty cells in the range $(i1, j), (i1 + 1, j), ..., (i2, j)$.
 *
 * Define the following dp:
 *
 * If $(i, j)$ is `D`:
 *
 * $$
 * dp(i, j) = dp(i + 1, j) \times 3^{rowcnt_i(j + 1, w)}
 * $$
 *
 * If $(i, j)$ is `R`:
 * $$
 * dp(i, j) = dp(i, j + 1) \times 3^{colcnt_i(i + 1, h)}
 * $$
 *
 * If $(i, j)$ is `X`:
 *
 * $$
 * dp(i, j) = dp(i + 1, j) \times 3^{rowcnt_i(j + 1, w)}
 * + dp(i, j + 1) \times 3^{colcnt_i(i + 1, h)}
 * $$
 *
 * If $(i, j)$ is empty:
 *
 * $$
 * dp(i, j) = 2 \ times dp(i + 1, j) \times 3^{rowcnt_i(j + 1, w)}
 * + 2 \times dp(i, j + 1) \times 3^{colcnt_i(i + 1, h)}
 * $$
 *
 * The $2$ comes because to turn right one has $|{R, X}| = 2$ options. Similarly
 * for turning down.
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = atcoder::modint998244353;

ll solve(vector<string> mat)
{
    int                  h = mat.size(), w = mat[0].size();
    vector<vector<mint>> dp(h + 1, vector<mint>(w + 1, 0));

    mint         miss_right(1);
    vector<mint> miss_down(w, 1);

    for (int i = h - 1; i >= 0; --i)
    {
        miss_right = 1;
        for (int j = w - 1; j >= 0; --j)
        {
            mint dans = dp[i + 1][j] * miss_right;
            mint rans = dp[i][j + 1] * miss_down[j];

            int md, mr;
            if (auto c = mat[i][j]; c)
            {
                md = c == 'X' or c == 'D';
                mr = c == 'X' or c == 'R';
            }
            else // c is empty
            {
                md = mr = 2;
                miss_right *= 3;
                miss_down[j] *= 3;
            }

            dp[i][j] = dans * md + rans * mr;
            if (i == h - 1 and j == w - 1)
                dp[i][j] = !mat[i][j] ? 3 : 1;
        }
    }

    return dp[0][0].val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> mat(h, string(w, 0));
    for (int i = 0; i < k; ++i)
    {
        int  row, col;
        char ch;
        cin >> row >> col >> ch, row--, col--;
        mat[row][col] = ch;
    }

    cout << solve(mat) << endl;

    return 0;
}
