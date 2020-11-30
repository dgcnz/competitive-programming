/** @file
 * @date                2020-11-30
 * @url                 https://atcoder.jp/contests/abc057/tasks/abc057_c
 * @tags                number_theory, divisors
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       2
 * @coding_time         3
 * @time_complexity     O(\sqrt{n})
 * @memory_complexity   O(1)
 * @idea
 * Brute-force up to $\sqrt{n}$.
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
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;

    int ans = 64;
    for (int i = 1, m = sqrt(n); i <= m; ++i)
        if (n % i == 0)
            ans = min(ans, 1 + (int)log10(n / i));

    cout << ans << endl;

    return 0;
}
