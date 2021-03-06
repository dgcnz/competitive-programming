#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 3e5 + 11;

int    n, m, visited[NMAX], dp[NMAX][26];
vi     g[NMAX], order;
string ch;

bool dfs1(int u)
{
    if (visited[u] == 1)
        return false;
    if (visited[u] == 2)
        return true;

    visited[u] = 1;
    for (auto v : g[u])
        if (not dfs1(v))
            return false;

    visited[u] = 2;
    order.push_back(u);
    return true;
}

bool toposort(void)
{
    memset(visited, 0, sizeof(visited));
    for (int u = 0; u < n; ++u)
        if (not visited[u] and not dfs1(u))
            return false;
    return true;
}

void dfs2(int u)
{
    if (visited[u])
        return;
    for (auto v : g[u])
    {
        dfs2(v);
        for (int c = 0; c < 26; ++c)
            dp[u][c] = max(dp[u][c], dp[v][c]);
    }

    visited[u] = true;
    dp[u][ch[u] - 'a']++;
}

int solve(void)
{
    int ans = 0;
    memset(visited, 0, sizeof(visited));
    reverse(all(order));
    for (auto u : order)
    {
        if (not visited[u])
        {
            dfs2(u);
            ans = max(ans, *max_element(dp[u], dp[u] + 26));
        }
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int u, v;
    cin >> n >> m >> ch;

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
    }

    if (toposort())
        cout << solve() << endl;
    else
        cout << -1 << endl;

    return 0;
}
