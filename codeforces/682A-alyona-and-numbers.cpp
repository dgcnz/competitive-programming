/** @file
 * @date                2020-12-31
 * @url                 https://codeforces.com/problemset/problem/682/A
 * @tags                math, modulo
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         10
 * @time_complexity     O(1)
 * @memory_complexity   O(\max(n, m))
 * @idea
 * So, we must pair numbers with remainder $x$ with those with remainder $5-x$,
 * $\mod 5$. Since I'm lazy I just precomputed such counts in $O(\max(n, m))$.
 *
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

ll solve(int n, int m)
{
    vi nrem(5, 0), mrem(5, 0);
    for (int i = 1; i <= max(n, m); ++i)
    {
        int rem = i % 5;
        if (i <= n)
            nrem[rem]++;
        if (i <= m)
            mrem[rem]++;
    }

    ll ans = 0;
    for (int i = 0; i < 5; ++i)
        ans += ll(nrem[i]) * ll(mrem[(5 - i) % 5]);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
    return 0;
}
