/** @file
 * @date                2021-03-13
 * @url                 https://atcoder.jp/contests/abc142/tasks/abc142_e
 * @tags                dp, forward_dp
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         30
 * @time_complexity     O(m2^n)
 * @memory_complexity   O(m2^n)
 * @idea
 *
 * Since n is very small, we can do bitmask dp:
 *
 * $dp(mask, i)$: minimum cost to unlock the boxes on mask using the first $i$
 * keys.
 *
 * Doing forward dp we can compute `dp[mask|key[i]]`.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(int n, vi cost, vi key)
{
    int       m   = cost.size();
    int const INF = 1e9;

    vector<vi> dp((1 << n), vi(m + 1, INF));

    fill(all(dp[0]), 0);
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        for (int i = 0; i < m; ++i)
        {
            int fmask = mask | key[i];
            if (i > 0)
                dp[mask][i] = min(dp[mask][i], dp[mask][i - 1]);
            dp[fmask][i + 1] =
                min({dp[fmask][i + 1], dp[fmask][i], dp[mask][i] + cost[i]});
        }
    }
    return dp[(1 << n) - 1][m];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vi cost(m), key(m);
    for (int i = 0; i < m; ++i)
    {
        int b;
        cin >> cost[i] >> b;
        key[i] = 0;
        while (b--)
        {
            int c;
            cin >> c, c--;
            key[i] |= 1 << c;
        }
    }
    if (auto ans = solve(n, cost, key); ans != 1e9)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
