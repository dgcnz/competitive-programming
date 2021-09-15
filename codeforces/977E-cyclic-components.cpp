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
 
int solve(int n, vector<ii> edges)
{
    Graph g(n);
 
    for (auto [u, v] : edges)
        g[u].push_back(v), g[v].push_back(u);
 
    int          ans = 0;
    vector<bool> vis(n, false);
    for (int u = 0; u < n; ++u)
    {
        if (not vis[u])
        {
            bool                cur = true;
            function<void(int)> dfs = [&](int u) {
                vis[u] = true;
                cur &= (g[u].size() == 2);
                for (auto v : g[u])
                    if (!vis[v])
                        dfs(v);
            };
            dfs(u);
            ans += cur;
        }
    }
    return ans;
}
 
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
 
    vector<ii> edges(m);
    for (auto &[u, v] : edges)
        cin >> u >> v, u--, v--;
 
    cout << solve(n, edges) << endl;
 
    return 0;
}
