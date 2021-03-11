/** @file
 * @date                2021-01-30
 * @url                 https://atcoder.jp/contests/abc190/tasks/abc190_d
 * @tags                math, number_theory
 * @status              AC
 * @score               2
 * @difficulty          3
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       60
 * @coding_time         4
 * @time_complexity     O(\sqrt{n})
 * @memory_complexity   O(1)
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/87349)
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
    n *= 2;

    int ans = 0;
    for (ll k = 1, sqn = sqrt(n); k <= sqn; ++k)
        if (n % k == 0 and (n / k - k + 1) % 2 == 0)
            ans += 2;

    cout << ans << endl;

    return 0;
}
