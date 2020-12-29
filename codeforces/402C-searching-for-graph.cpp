/** @file
 * @date                2020-12-29
 * @url                 https://codeforces.com/problemset/problem/402/C
 * @tags                greedy, graphs, constructive
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         4
 * @time_complexity     O(n)
 * @memory_complexity   O(1)
 * @idea
 * So, intuitively, we want edges to be uniformly distributed on the vertices,
 * as to minimize the maximum edges for each subgraph in the hope that it fits
 * the problem's constraints.
 *
 * One way to do so is to add edges in lexicographical order.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, p, m;
        cin >> n >> p;

        m = 2 * n + p;
        for (int u = 1; u < n; ++u)
        {
            for (int v = u + 1; v <= n; ++v)
            {
                if (!m)
                    break;
                cout << u << " " << v << endl;
                m--;
            }
            if (!m)
                break;
        }
    }
    return 0;
}
