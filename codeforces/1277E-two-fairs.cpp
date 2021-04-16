#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b, a--, b--;
        vector<vi> g(n);
        while (m--)
        {
            int u, v;
            cin >> u >> v, u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<bool> vis(n, false);

        function<int(int, int)> dfs = [&](int u, int exc) {
            int cnt = 1;
            vis[u]  = true;
            for (auto v : g[u])
                if (!vis[v] and v != exc)
                    cnt += dfs(v, exc);
            return cnt;
        };

        ll x = dfs(a, b);
        fill(all(vis), false);
        ll y = dfs(b, a);
        cout << (n - x - 1) * (n - y - 1) << endl;
    }
    return 0;
}
