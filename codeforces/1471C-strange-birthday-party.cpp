/** @file
 * @date                2021-01-05
 * @url                 https://codeforces.com/contest/1471/problem/C
 * @tags                sorting, greedy
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       12
 * @coding_time         4
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Assign people with higher default cost, $k_i$, to the presents with lower
 * cost.
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

ll solve(vi k, vi c)
{
    sort(all(k), greater<int>());

    int cur = 0;
    ll  ans = 0;
    for (auto &ki : k)
    {
        if (cur < ki)
            ki = cur++;
        ans += c[ki];
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vi k(n), c(m);
        for (auto &ki : k)
            cin >> ki, ki--;
        for (auto &ci : c)
            cin >> ci;
        cout << solve(k, c) << endl;
    }
    return 0;
}
