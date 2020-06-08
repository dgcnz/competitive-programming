#include <bits/stdc++.h>

using namespace std;
using vi  = vector<int>;
using ii  = pair<int, int>;
using vii = vector<ii>;
using ll  = long long;

const int NMAX = 1e5 + 11;

vii g[NMAX];
int cost[NMAX];
ll  dp[NMAX], dp2[NMAX];

// dp1(u) = cost of traversing the whole subtree rooted at u and finishing on u
// dp2(u) = cost of traversing the subtree of u until all nodes are visited once

void compdp(int u, int p)
{
    dp[u]   = 0;
    dp2[u]  = 0;
    ll vmin = LLONG_MAX;
    for (auto [v, c] : g[u])
    {
        if (v == p)
            continue;
        cost[v] = c;

        compdp(v, u);
        dp[u] += dp[v] + 2 * c;
        vmin = min(vmin, dp2[v] - dp[v] - c);
    }
    dp2[u] = dp[u];

    if (vmin != LLONG_MAX)
        dp2[u] += vmin;
}

int main(void)
{
    int n, x, y, w;

    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    compdp(1, 0);
    cout << dp2[1] << endl;
    return 0;
}
