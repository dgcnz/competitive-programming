/** @file
 * @date                2020-12-11
 * @url                 https://codeforces.com/contest/1461/problem/B
 * @tags                dp, brute_force
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       40
 * @coding_time         4
 * @time_complexity     O(n^2)
 * @memory_complexity   O(n^2)
 * @idea
 * Note that you can know what is the largest spruce that can be constructed
 * with root $(r, c)$, by merging the spruces at $(r + 1, c - 1)$, $(r + 1, c)$
 * and $(r + 1,c + 1)$ and cutting the excess. With this idea in mind, define
 * the following dp state:
 *
 * $$ dp(r, c) = 1 + min(dp(r + 1, c - 1), dp(r + 1, c), dp(r + 1, c + 1)) $$
 *
 * if $(r, c) == '*'$.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;

int const NMAX = 500 + 11;

int n, m, board[NMAX][NMAX];

ll solve(void)
{
    ll ans = 0;
    for (int r = n; r >= 1; --r)
    {
        for (int c = m; c >= 1; --c)
        {
            if (board[r][c])
            {
                board[r][c] = 1 + min({board[r + 1][c - 1],
                                       board[r + 1][c],
                                       board[r + 1][c + 1]});
                ans += board[r][c];
            }
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(board, 0, sizeof board);
        for (int r = 1; r <= n; ++r)
        {
            for (int c = 1; c <= m; ++c)
            {
                char ch;
                cin >> ch;
                board[r][c] = (ch == '*');
            }
        }
        cout << solve() << endl;
    }
    return 0;
}
