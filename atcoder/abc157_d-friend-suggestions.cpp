/** @file
 * @date                2020-12-18
 * @url                 https://atcoder.jp/contests/abc157/tasks/abc157_d
 * @tags                dsu, graphs
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        2
 * @thinking_time       25
 * @coding_time         10
 * @time_complexity     O((n + k) \alpha(n))
 * @memory_complexity   O(n + m + n + k)
 * @idea
 * Let's solve first a simpler version of the problem, where there are no
 * blocking relations.
 *
 * Let's build a friendship graph.
 *
 * Note for a given person $i$, every person in the connected component that is
 * not a direct friend or $i$ itself is a friend candidate.
 *
 * So, the answer is computed like:
 *
 * $$ ans[i] = | C_i | - | F_i | - 1$$
 *
 * Where, $C_i$ is the connected component where $i$ lies and $F_i$ the
 * friendships $i$ has.
 *
 * In the real problem, however, the friendship component where $i$ is might
 * have blocked people. To handle this, decrease by 1 for each blocked person
 * that is in the same connected component. This can be efficiently done with a
 * Disjoint Set Union structure.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <atcoder/dsu>
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

    int n, m, k;
    cin >> n >> m >> k;

    atcoder::dsu d(n);
    vector<vi>   blocked(n, vi());
    vector<vi>   friends(n, vi());

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b, a--, b--;
        d.merge(a, b);
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 0; i < k; ++i)
    {
        int c, d;
        cin >> c >> d, c--, d--;
        blocked[c].push_back(d);
        blocked[d].push_back(c);
    }

    vi ans(n, 0);

    for (int i = 0; i < n; ++i)
    {
        ans[i] = d.size(i) - isz(friends[i]) - 1;
        for (auto j : blocked[i])
            ans[i] -= d.same(i, j);
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
