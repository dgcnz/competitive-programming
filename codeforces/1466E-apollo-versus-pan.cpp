/* @file
 * @date                2020-12-30
 * @url                 https://codeforces.com/contest/1466/problem/E
 * @tags                math, bitmask
 * @status              AC
 * @score               3
 * @difficulty          4
 * @editorial           yes
 * @reading_time        2
 * @thinking_time       90
 * @coding_time         20
 * @time_complexity     O(n \log{x_{max}})
 * @memory_complexity   O(n)
 * @idea
 *
 * [Editorial](https://codeforces.com/blog/entry/86126) is pretty cool.
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
using namespace atcoder;

using ll   = long long;
using vi   = vector<int>;
using mint = modint1000000007;

int const BITSZ = 60;

int solve(vector<ll> a)
{
    int  n = isz(a);
    vi   cnt(BITSZ, 0);
    mint ans;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < BITSZ; ++j)
            cnt[j] += (a[i] >> j) & 1;

    for (int j = 0; j < n; ++j)
    {
        mint sum_or = 0, sum_and = 0;
        for (int b = 0; b < BITSZ; ++b)
        {
            if ((a[j] >> b) & 1)
            {
                sum_or += mint(1LL << b) * n;
                sum_and += mint(1LL << b) * cnt[b];
            }
            else
                sum_or += mint(1LL << b) * cnt[b];
        }
        ans += sum_or * sum_and;
    }

    return ans.val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;
        cout << solve(a) << endl;
    }
    return 0;
}
