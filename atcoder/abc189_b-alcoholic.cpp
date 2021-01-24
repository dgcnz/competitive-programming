/** @file
 * @date                2021-01-23
 * @url                 https://atcoder.jp/contests/abc189/tasks/abc189_b
 * @tags                implementation
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       2
 * @coding_time         3
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Linearly test if the $i$th liquor gets Takahashi drunk. To avoid precision
 * errors, multiply $x$ by $100$ instead of dividing each percentage by $100$.
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

int solve(vi v, vi p, ll x)
{
    int n   = isz(v);
    ll  cur = 0;
    x *= 100;
    for (int i = 0; i < n; ++i)
    {
        cur += v[i] * p[i];
        if (cur > x)
            return i + 1;
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vi v(n), p(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i] >> p[i];

    cout << solve(v, p, x);

    return 0;
}
