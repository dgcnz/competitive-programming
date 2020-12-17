/** @file
 * @date                2020-12-13
 * @url                 https://atcoder.jp/contests/abc185/tasks/abc185_b
 * @tags                implementation
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Simulate the battery through time.
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

bool solve(ll n, ll t, vector<ii> events)
{
    ll ct = 0, battery = n;
    events.emplace_back(t, t);
    for (auto [a, b] : events)
    {
        battery = max(0LL, battery - (a - ct));
        if (battery == 0)
            return false;

        battery = min(n, battery + b - a);
        ct      = b;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, t;

    cin >> n >> m >> t;
    vector<ii> events(m);
    for (auto &[a, b] : events)
        cin >> a >> b;

    cout << (solve(n, t, events) ? "Yes" : "No") << endl;
    return 0;
}
