/** @file
 * @date                2021-01-08
 * @url                 https://atcoder.jp/contests/abc169/tasks/abc169_b
 * @tags                math, implementation
 * @status              AC
 * @score               0
 * @difficulty          1
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Test for $a_i \leq \frac{10^{18}}{\text{ans}}$.
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

ll solve(vector<ll> a)
{
    if (auto it = find(all(a), 0LL); it != a.end())
        return 0LL;
    ll ans = 1, maxv = 1e18;
    for (auto ai : a)
    {
        if (ai <= maxv / ans)
            ans *= ai;
        else
            return -1;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;

    cout << solve(a) << endl;

    return 0;
}
