/** @file
 * @date                2021-01-30
 * @url                 https://atcoder.jp/contests/abc190/tasks/abc190_c
 * @tags                bitmasks, brute_force
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         25
 * @time_complexity     O(2^k (n + m))
 * @memory_complexity   O(n + m)
 * @idea
 * Let's iterate over all possible configurations of dishes and pick the one
 * which fulfills the most conditions.
 *
 * Since $k \leq 16$ we can do this by defining a bitmask where:
 * - $b(i, j)$ : if $j = 0$,  $c_i$ is taken, if $j = 0$, then $d_i$ is taken.
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
using ii = array<int, 2>;
using vi = vector<int>;

ll solve(vector<ii> conditions, vector<ii> options, int n)
{
    int         k = options.size();
    vector<int> balls(n);
    ll          ans = 0;

    for (int mask = 0; mask < (1 << k); ++mask)
    {
        fill(all(balls), 0);
        for (int i = 0; i < k; ++i)
        {
            int j = (mask >> i) & 1;
            balls[options[i][j]]++;
        }

        ll cur = 0;
        for (auto [u, v] : conditions)
            cur += balls[u] && balls[v];
        ans = max(ans, cur);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;

    cin >> n >> m;
    vector<ii> conditions(m);

    for (auto &[u, v] : conditions)
        cin >> u >> v, u--, v--;

    int k;
    cin >> k;
    vector<ii> options(k);

    for (auto &[u, v] : options)
        cin >> u >> v, u--, v--;

    cout << solve(conditions, options, n) << endl;

    return 0;
}
