#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/scc>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vi c, vi a)
{
    int        n = c.size();
    scc_graph  g(n);
    vector<vi> gr(n);
    for (int i = 0; i < n; ++i)
    {
        g.add_edge(i, a[i]);
        gr[a[i]].push_back(i);
    }

    auto scc = g.scc();
    reverse(all(scc));

    vector<bool>        vis(n, false);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v : gr[u])
            if (!vis[v])
                dfs(v);
    };

    ll ans = 0;
    for (auto comp : scc)
    {
        if (vis[comp.back()])
            continue;
        ll cur = 1e15;
        for (auto v : comp)
            cur = min(cur, (ll)c[v]);

        dfs(comp.back());
        ans += cur;
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> c(n), a(n);
    read(all(c)), read(all(a));
    transform(all(a), begin(a), [](int ai) { return ai - 1; });

    cout << solve(c, a) << endl;

    return 0;
}
