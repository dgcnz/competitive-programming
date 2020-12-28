/** @file
 * @date                2020-12-26
 * @url                 https://codeforces.com/problemset/problem/330/B
 * @tags                graph, brute_force
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       3
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Note that the constraint (distance between pairs is at most $2$) will only be
 * satisfied by a star graph (all nodes connected to a center node). The problem
 * reduces to find a center for such graph and connect all other nodes to it.
 *
 * Note that there's always an answer because of the $m < \frac{n}{2}$
 * constraint.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<bool> is_center(n, true);
    while (m--)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        is_center[u] = is_center[v] = false;
    }

    int root =
        distance(begin(is_center),
                 find_if(all(is_center), [](bool flag) { return flag; }));

    cout << n - 1 << endl;
    for (int u = 0; u < n; ++u)
    {
        if (u == root)
            continue;
        cout << root + 1 << " " << u + 1 << endl;
    }

    return 0;
}
