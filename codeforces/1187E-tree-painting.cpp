#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

const int NMAX = 2e5 + 11;

// Algorithm:
// 1) Compute the size of each subtree
// 2) Root the tree arbitrarily and compute dp for that root
// 3) Run DFS and reroot as you go while picking the best solution

vi  g[NMAX];
int sz[NMAX];
ll  dp[NMAX], ans = 0;

int compsz(int u, int p)
{
    sz[u] = 1;
    for (auto v : g[u])
    {
        if (v == p)
            continue;

        sz[u] += compsz(v, u);
    }
    return sz[u];
}

ll compdp(int u, int p)
{
    dp[u] = sz[u];
    for (auto v : g[u])
    {
        if (v == p)
            continue;

        dp[u] += compdp(v, u);
    }
    return dp[u];
}

// dp(u) = sz[u] + sum (dp(v))
void dfs(int u, int p)
{
    ans = max(ans, dp[u]);
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        // reroot

        dp[u] -= dp[v];
        dp[u] -= sz[v];
        sz[u] -= sz[v];

        dp[v] += dp[u];
        dp[v] += sz[u];
        sz[v] += sz[u];

        dfs(v, u);

        // undo

        sz[v] -= sz[u];
        dp[v] -= sz[u];
        dp[v] -= dp[u];

        sz[u] += sz[v];
        dp[u] += sz[v];
        dp[u] += dp[v];
    }
}

int main(void)
{
    int n, u, v;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    compsz(0, -1);
    compdp(0, -1);
    dfs(0, -1);

    cout << ans << endl;

    return 0;
}
