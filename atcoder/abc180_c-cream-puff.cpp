/** @file
 * @date                2021-01-08
 * @url                 https://atcoder.jp/contests/abc180/tasks/abc180_c
 * @tags                divisibility, factors, number_theory, implementation
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         5
 * @time_complexity     O(\sqrt{n} \log{\sqrt{n}})
 * @memory_complexity   O(2 \sqrt{n})
 * @idea
 * Get factors up to $\sqrt{n}$ (with their co-factors) and print them.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;

    set<ll> factors;
    for (ll x = 1, sq = sqrt(n); x <= sq; ++x)
    {
        if (n % x == 0)
        {
            factors.insert(x);
            factors.insert(n / x);
        }
    }
    for (auto x : factors)
        cout << x << endl;

    return 0;
}
