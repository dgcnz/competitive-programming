/** @file
 * @date                2021-01-31
 * @url                 https://atcoder.jp/contests/abc181/tasks/abc181_b
 * @tags                math, easy
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       2
 * @coding_time         3
 * @time_complexity     O(n)
 * @memory_complexity   O(1)
 * @idea
 * Each operation $a, b$, is equivalent to increasing the answer by $sq(b) -
 * sq(a)$, where $sq(n)$ is the sum of the first $n$ natural numbers.
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

ll sq(ll n) { return (n * (n + 1)) / 2; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;

        ans += sq(b) - sq(a - 1);
    }

    cout << ans << endl;
    return 0;
}
