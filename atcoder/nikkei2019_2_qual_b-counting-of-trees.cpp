/** @file
 * @date                2020-12-09
 * @url https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_b
 * @tags                counting, constructive, dp
 * @status              AC
 * @score               2
 * @difficulty          4
 * @editorial           yes
 * @reading_time        5
 * @thinking_time       90
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 *
 * Note that no tree can be made if our given array doesn't fullfill the
 * following properties:
 *
 * 1. The distance of node $1$ to itself ($d_1$) is not $0$.
 * 2. There are exists a node $i \neq 1$ that has distance $d_i = 0$.
 * 3. There exists a distance $d_{missing} \leq d_i$ for some $d_i$, such that
 * $d_{missing} \notin D$.
 *
 * From now on we'll assume otherwise.
 *
 * The idea is to construct the answer by adding layers of nodes with the same
 * distance to the root. We'll compute the solution for a certain distance $i$
 * by counting all the ways in which we can place the nodes at distance $i$ on
 * the nodes at distance $i-1$. For each current node we would have $cnt_{i-1}$
 * options, so in total there would be $cnt_{i-1}^{cnt_i}$ ways to construct one
 * more layer of the tree.
 *
 * A simple dp works:
 *
 * $$ dp(i) = dp(i - 1) \times cnt_{i - 1}^{cnt_i} $$
 *
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
using ii = pair<int, int>;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

ll const MOD = 998244353;

ll solve(vector<int> d)
{
    int n = isz(d), m = 0;

    vector<int> cnt(n, 0);
    vector<ll>  dp(n, 0);

    for (auto di : d)
        cnt[di]++, m = max(m, di);

    if (d[0] != 0 or cnt[0] > 1)
        return 0;

    dp[0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        if (cnt[i] == 0)
            return 0;
        dp[i] = dp[i - 1];
        for (int j = 0; j < cnt[i]; ++j)
            dp[i] = (dp[i] * cnt[i - 1]) % MOD;
    }

    return dp[m];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> d(n);
    read_n(begin(d), n);
    cout << solve(d) << endl;

    return 0;
}
