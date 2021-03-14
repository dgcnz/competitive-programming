/** @file
 * @date                2021-03-13
 * @url                 https://atcoder.jp/contests/abc195/tasks/abc195_d
 * @tags                greedy
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       40
 * @coding_time         20
 * @time_complexity     O(qn \log{m})
 * @memory_complexity   O(n)
 * @idea
 * Let's call `x'` to the resulting increasing sequence after deleting boxes `L`
 * to `R` from `x` and sorting it.
 *
 * How can we place baggages in order to maximize total value?
 *
 * The first observation is that it is always optimal to place the k,
 * (`k <= |x'|`), most valuable baggages (that can possibly fit in the boxes).
 *
 * How do we find such baggages?
 *
 * Let's say we sort the baggages increasingly by value and decreasingly by
 * weight. Let's start placing them in the smallest box they can fit. After
 * considering all baggages, the ones that fit in this order will consist the
 * answer.
 *
 * To have an idea why, say that the ith most valuable baggage is the first one
 * that can't fit. Note that it's always optimal to just throw away that
 * baggage, otherwise we would have to make space of it throwing one we already
 * placed (which, by the order we enforced would have higher value).
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
    int n, m, q;
    cin >> n >> m >> q;

    vector<ii> vw(n);
    for (auto &[v, w] : vw)
        cin >> w >> v, v *= -1;

    vi x(m);
    for (auto &xi : x)
        cin >> xi;

    sort(all(vw));
    while (q--)
    {
        int l, r;
        cin >> l >> r, l--, r--;
        multiset<int> xp;
        for (int i = 0; i < m; ++i)
            if (i < l or r < i)
                xp.insert(x[i]);

        ll ans = 0;
        // sorted increasingly by value, decreasingly by weight
        for (auto [v, w] : vw)
        {
            // Lowest x = *it such that x >= w
            auto it = xp.lower_bound(w);
            if (it != xp.end())
            {
                xp.erase(it);
                ans += -v;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
