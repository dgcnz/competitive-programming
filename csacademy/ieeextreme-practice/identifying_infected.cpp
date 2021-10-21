#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/blockcut>
#include <cplib/graph/pathqueries>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using S = int;
S op(S a, S b) { return a + b; }
S inv(S a) { return -a; }
S e() { return 0; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    Graph<void> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g.add_undirected_edge(u, v);
    }

    BlockCut<void> bc(g);
    int            C = bc.tree.size();
    vector<int>    cut(C);

    for (int u = 0; u < n; ++u)
        cut[bc.id[u]] = bc.cut[u];

    PathQueries<void, S, op, inv, e> solver(bc.tree, cut);

    int q;
    cin >> q;
    while (q--)
    {
        int f, s;
        cin >> f >> s, f--, s--;

        int ans = solver.query(bc.id[f], bc.id[s]) + !bc.cut[f] + !bc.cut[s];
        cout << ans << endl;
    }
    return 0;
}
