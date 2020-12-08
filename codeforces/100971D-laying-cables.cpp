/** @file
 * @date                2020-12-07
 * @url                 https://codeforces.com/gym/100971/problem/D
 * @tags                sorting, implementation
 * @status              AC
 * @score               1
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         15
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * We'll maintain two sets:
 * 1. `ordx`: Elements ordered by their position $x$.
 * 2. `ordp`: Elements ordered by their population $p$.
 *
 * First note that to compute the parent of a city, we don't need information
 * about any city with less population.
 *
 * So, we'll compute the parent for each city (in increasing order of
 * population) and remove such city from the set of candidates `ordx`. Since all
 * cities with less population have been removed from `ordx`, the immediate
 * neighbors of the current city in `ordx` will be our candidates. Pick the
 * closest and biggest city.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using vi  = vector<int>;
using iii = tuple<int, int, int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ii> a(n);
    set<ii>    ordx, ordp;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        ordx.emplace(a[i].first, i);
        ordp.emplace(a[i].second, i);
    }

    vi ans(n);
    for (auto [p, i] : ordp)
    {
        int  x   = a[i].first;
        auto it  = ordx.lower_bound({x, 0});
        iii  cur = {1e9, 0, -2};

        if (next(it) != end(ordx))
        {
            int j = next(it)->second;
            cur   = min(cur, {abs(a[j].first - x), -a[j].second, j});
        }
        if (it != begin(ordx))
        {
            int j = prev(it)->second;
            cur   = min(cur, {abs(a[j].first - x), -a[j].second, j});
        }
        ans[i] = get<2>(cur) + 1;
        ordx.erase(it);
    }

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
