/** @file
 * @date                2021-01-10
 * @url                 https://atcoder.jp/contests/abc188/tasks/abc188_d
 * @tags                greedy, sweep_line
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         15
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Greedily pay for Snuke Prime or not if the accumulated cost of the interval
 * exceeds the price of a subscription.
 *
 * To ease implementation, for each interval `[l, r]`, you can merge all `l`'s
 * with the same value and all `r`'s with the same value. Then apply standard
 * sweep line to compute the answer.
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
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, ll>;
using vi  = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll  C;
    cin >> n >> C;

    vector<iii>  events;
    map<int, ll> A, B;

    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        A[a] += c;
        B[b] += c;
    }
    for (auto [k, v] : A)
        events.emplace_back(k, -1, v);

    for (auto [k, v] : B)
        events.emplace_back(k, +1, v);

    sort(all(events));
    ll  unit_cost = 0, paying_cost = 0, ans = 0;
    int ct = 0;
    for (auto [t, sign, c] : events)
    {
        sign *= -1;
        if (sign == +1) // open
            ans += (t - ct) * paying_cost;
        else
            ans += (t - ct + 1) * paying_cost;

        unit_cost += sign * c;
        paying_cost = (unit_cost > C ? C : unit_cost);
        ct          = (sign == 1 ? t : t + 1);
    }
    cout << ans << endl;

    return 0;
}
