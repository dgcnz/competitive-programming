#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graphs/dfs_visitor>
#include <cplib/graphs/unweighted_graph>

using namespace std;
using namespace cplib;
using ll    = long long;
using ii    = tuple<int, int>;
using Graph = UnweightedGraph;

bool solve(vector<ll> a, vector<ll> b, vector<ii> edges)
{
    int   n = a.size();
    Graph g(n);
    g.add_edges<false>(edges);

    struct Visitor : public DFSVisitor<Graph>
    {
        ll         a_sum = 0, b_sum = 0;
        bool       ok = true;
        vector<ll> a, b;
        Visitor(const Graph &g, vector<ll> a, vector<ll> b)
            : DFSVisitor(g), a(a), b(b){};
        void discover_vertex(int u) { a_sum += a[u], b_sum += b[u]; }
        void end_search([[maybe_unused]] int s)
        {
            ok &= a_sum == b_sum;
            a_sum = b_sum = 0;
        }

    } vis(g, a, b);
    g.dfs(0, vis);
    return vis.ok;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(n);

    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;

    vector<ii> edges(m);
    for (auto &[u, v] : edges)
        cin >> u >> v, u--, v--;

    cout << (solve(a, b, edges) ? "Yes" : "No") << endl;

    return 0;
}
