/** @file
 * @date                2020-12-27
 * @url                 https://codeforces.com/problemset/problem/292/B
 * @tags                graphs, implementation
 * @status              AC
 * @score               1
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         15
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Given a connected graph, $G$, with $n$ nodes, you can determine it's type by
 * its distribution of node-degrees.
 *
 * - bus: $n-2$ nodes with degree $2$, and $2$ nodes with degree $1$ (the
 * extremes).
 * - ring: $n$ nodes of degree $2$.
 * - star: $n - 1$ nodes with degree $1$ and $1$ node with degree $n-1$.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string solve(vi d)
{
    auto dgone = [](int dg) { return dg == 1; };
    auto dgtwo = [](int dg) { return dg == 2; };

    int n = isz(d);
    sort(all(d));

    if (all_of(all(d), dgtwo))
        return "ring topology";
    if (all_of(begin(d) + 2, end(d), dgtwo) and
        all_of(begin(d), begin(d) + 2, dgone))
        return "bus topology";
    if (d.back() == n - 1 and all_of(begin(d), end(d) - 1, dgone))
        return "star topology";
    return "unknown topology";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vi d(n, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        d[u]++, d[v]++;
    }

    cout << solve(d) << endl;

    return 0;
}
