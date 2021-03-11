/** @file
 * @date                2021-01-29
 * @url                 https://codeforces.com/contest/1476/problem/D
 * @tags                dsu, graphs
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * As the problem states, each country has two states (original roads and
 * reversed roads). Let's picture this with a bipartite graph, where each city
 * has two corresponding nodes. For a given city $u$, let's call its
 * corresponding node on the original roads $id0(u)$ and $id1(1)$ on the
 * reversed roads.
 *
 * The ith road in this graph will connect $id0(i - 1)$ and  $id1(i)$ if it's a
 * `R` road and $id0(i)$ and $id1(i - 1)$ otherwise.
 *
 * Note that such edges can be considered undirected, since each time one edge
 * is taken all of them should be reversed.
 *
 * Using this, note that the answer of a given city $u$ is the size of the
 * connected component that $id0(u)$ lies on.
 *
 * We can use a dfs or a disjoint set union to compute this efficiently.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

vi solve(string s)
{
    int  n   = s.size();
    auto id0 = [](int u) { return 2 * u; };
    auto id1 = [](int u) { return 2 * u + 1; };

    atcoder::dsu dsu(2 * (n + 1));
    for (int i = 1; i <= n; ++i)
    {
        if (s[i - 1] == 'L')
            dsu.merge(id0(i), id1(i - 1));
        else
            dsu.merge(id0(i - 1), id1(i));
    }

    vi ans(n + 1);
    for (int i = 0; i <= n; ++i)
        ans[i] = dsu.size(2 * i);

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int    n;
        string s;
        cin >> n >> s;

        auto ans = solve(s);
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
