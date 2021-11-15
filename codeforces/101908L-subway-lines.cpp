#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/graph>
#include <cplib/graph/pathqueries>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using S  = int;
S op(S a, S b) { return a + b; }
S inv(S a) { return -a; }
S e() { return 0; }

int const INF = 1e9;
int       main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    Graph<void> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g.add_undirected_edge(u, v);
    }
    vector<int>                      X(n, 1);
    PathQueries<void, S, op, inv, e> solver(g, X);
    while (q--)
    {
        vector<vi> v(2, vi(2));
        read(all(v[0]));
        read(all(v[1]));
        decrement(all(v[0]));
        decrement(all(v[1]));

        vector<int> l(2);
        for (int i = 0; i < 2; ++i)
            l[i] = solver.lca(v[i][0], v[i][1]);

        vector<int> joints;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                for (int k = 0; k < 2; ++k)
                {
                    auto joint = solver.lca(v[i][j], v[1 - i][k]);
                    if (solver.query(joint) >= solver.query(l[i]) and
                        solver.query(joint) >= solver.query(l[1 - i]))
                        joints.emplace_back(joint);
                }
            }
        }
        auto ans = [&]()
        {
            switch (joints.size())
            {
            case 0:
                return 0;
            case 1:
                return 1;
            default:
                int x = 0;
                for (int i = 1; i < (int)joints.size(); ++i)
                    for (int j = 0; j < i; ++j)
                        x = max(x, solver.query(joints[i], joints[j]));
                return x;
            }
        }();
        cout << ans << endl;
    }
    return 0;
}
