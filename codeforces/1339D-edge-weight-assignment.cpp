#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ii solve(vector<vi> g)
{
    int n = g.size();

    vector<int> depth(n, 0);
    vector<int> leaf(n, true);

    int                      mx  = n - 1;
    function<void(int, int)> dfs = [&](int u, int p) {
        int leaves = 0;
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            depth[v] = depth[u] + 1;
            leaf[u]  = false;
            dfs(v, u);
            if (leaf[v])
                leaves++;
        }
        if (leaves)
            mx -= (leaves - 1);
    };

    int root = 0;
    for (int u = 0; u < n; ++u)
        if (g[u].size() > g[root].size())
            root = u;

    dfs(root, -1);
    vector<int> parity(2, 0);
    for (int u = 0; u < n; ++u)
        if (leaf[u])
            parity[depth[u] % 2]++;

    int mn = 1;
    if (parity[0] and parity[1])
        mn = 3;

    return {mn, mx};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<vi> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto [mn, mx] = solve(g);
    cout << mn << " " << mx << endl;
    return 0;
}
