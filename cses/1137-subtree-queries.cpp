#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#include <cplib/graphs/subtree_queries>

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using Tree = UnweightedTree;

using S = ll;
S op(S a, S b) { return a + b; }
S e() { return 0; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<ll> val(n);
    for (auto &x : val)
        cin >> x;

    Tree g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g.add_edge<false>(u, v);
    }

    SubtreeQueries<segtree, S, op, e> ans(g, 0, val);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u, x;
            cin >> u >> x, u--;
            ans.set(u, ll(x));
        }
        else
        {
            int u;
            cin >> u, u--;
            cout << ans.query(u) << endl;
        }
    }
    return 0;
}
