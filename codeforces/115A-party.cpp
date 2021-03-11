/** @file
 * @date                2021-02-01
 * @url                 https://codeforces.com/contest/115/problem/A
 * @tags                graphs, dfs, dag
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       3
 * @coding_time         5
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * Since each group can't have any relationship between different hierarchies,
 * all the people from the longest path in the graph must be in different
 * groups.
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
using ll    = long long;
using ii    = pair<int, int>;
using vi    = vector<int>;
using Graph = vector<vi>;

int solve(Graph g)
{
    int          n = g.size();
    vector<bool> vis(n);
    vector<int>  height(n);

    function<int(int)> dfs = [&](int u) {
        vis[u]    = true;
        height[u] = 1;
        for (auto v : g[u])
        {
            if (not vis[v])
                dfs(v);

            height[u] = max(height[u], height[v] + 1);
        }
        return height[u];
    };

    int ans = 0;
    for (int u = 0; u < n; ++u)
        if (not vis[u])
            ans = max(ans, dfs(u));
    return ans;
}

int main(void)
{
    int n;
    cin >> n;

    Graph g(n);
    for (int i = 0; i < n; ++i)
    {
        int pi;
        cin >> pi;
        if (pi != -1)
            g[i].push_back(pi - 1);
    }

    cout << solve(g) << endl;
    return 0;
}
