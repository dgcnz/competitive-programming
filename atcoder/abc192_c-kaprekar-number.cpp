/** @file
 * @date                2021-02-20
 * @url                 https://atcoder.jp/contests/abc192/tasks/abc192_c
 * @tags                math, implementation, brute_force
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         10
 * @time_complexity     O(k \log10{n})
 * @memory_complexity   O(\log10{n})
 * @idea
 * To compute $f(x)$ efficiently, you can use a counting sort variation to
 * construct $g1(x)$ and $g2(x)$ as integers.
 *
 * It should be fast enough to compute the first $k$ terms in the series.
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

ll solve(int n, int k)
{
    auto f = [](int x) {
        vi cnt(10, 0);
        while (x)
            cnt[x % 10]++, x /= 10;

        ll g1 = 0, g2 = 0;

        for (int d = 9; d >= 0; --d)
            for (int i = 0; i < cnt[d]; ++i)
                g1 *= 10, g1 += d;

        for (int d = 1; d <= 9; ++d)
            for (int i = 0; i < cnt[d]; ++i)
                g2 *= 10, g2 += d;

        return g1 - g2;
    };

    ll x = n;
    for (int i = 1; i <= k; ++i)
        x = f(x);
    return x;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    cout << solve(n, k) << endl;

    return 0;
}
