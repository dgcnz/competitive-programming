/** @file
 * @date                2021-03-18
 * @url https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_d
 * @tags                brute_force, graphs, observation, constructive
 * @status              AC
 * @score               4
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         20
 * @time_complexity     O(n + \sqrt{n})
 * @memory_complexity   O(n)
 * @idea
 * Let's say the answer consists of $k$ sets.
 * While considering set $i$, notice that it must share a common element with
 * all other $k - 1$ sets.
 *
 * You can picture it as a graph, where each sets
 * corresponds to a node and an edge $(u, v)$ with value $x$ denotes that they
 * share an element $x$.
 *
 * Observations:
 * 1. There are exactly $k - 1$ edges going out from each node. (Otherwise the
 * second constraint would be violated)
 * 2. There can't be two edges with the same value. (Otherwise the first
 * constraint would be violated)
 * 3. We already know a set has to share exactly $k - 1$ values with the
 * remaining sets, but we can conclude further that it must have exactly $k - 1$
 * values in total. If it were to have another value, the first constraint would
 * force another set to also contain it, yielding a contradiction.
 * 4. The number of edges of a complete graph is $\frac{n(n - 1)}{2}$.
 * 5. An answer for $n$ can only exist if there exists a complete graph with $m$
 * vertices, where $n = \frac{m(m - 1)}{2}$.
 *
 * Using these observations we can arrive a the following algorithm:
 * 1. Check if observation 5. holds
 * 2. For all edges in the complete graph assign a unique value from $1$ to $n$.
 * 3. Include the value from each edge to the sets that represent its endpoints.
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
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    int m = 1;
    while (m * (m - 1) < 2 * n) // O(sqrt(n))
        ++m;

    if (m * (m - 1) != 2 * n)
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
        cout << m << endl;
        vector<vi>   ans(m);
        vector<bool> vis(m, 0);

        for (int u = 0; u < m - 1; ++u)
            for (int v = u + 1; v < m; ++v)
                ans[u].push_back(n), ans[v].push_back(n--);

        for (auto &vals : ans)
        {
            cout << vals.size();
            for (auto x : vals)
                cout << " " << x;
            cout << endl;
        }
    }
    return 0;
}
