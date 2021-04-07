#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using ll = long long;

const int NMAX = 1e5 + 11;

int        n, leaves[NMAX];
ll         s, cost[NMAX], contribution[NMAX];
vector<ii> g[NMAX];

void dfs(int u, int p = 0)
{
    for (auto [v, w] : g[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        cost[v]         = w;
        contribution[v] = cost[v] * leaves[v];
        leaves[u] += leaves[v];
    }
    if (leaves[u] == 0) // is leaf
        leaves[u]++;
}

void reset(void)
{
    for (int u = 0; u < n; u++)
        g[u].clear();
    memset(contribution, 0, sizeof(contribution));
    memset(cost, 0, sizeof(cost));
    memset(leaves, 0, sizeof(leaves));
}

int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t, u, v, w;
    cin >> t;

    while (t--)
    {
        cin >> n >> s;
        reset();

        for (int i = 0; i < n - 1; ++i)
        {
            cin >> u >> v >> w, --u, --v;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

        dfs(0); // O(n)

        ll  sum = accumulate(contribution + 1, contribution + n, (ll)0);
        int ans = 0;

        set<pair<ll, int>, greater<pair<ll, int>>> edges;

        for (int u = 1; u < n; ++u) // O(nlogn)
            edges.insert({contribution[u] - (cost[u] / 2 * leaves[u]), u});

        while (sum > s) // O(nlogn)
        {
            auto it        = edges.begin();
            auto [diff, u] = *it;
            cost[u] /= 2;
            contribution[u] = leaves[u] * cost[u];
            sum -= diff;
            edges.erase(it);
            edges.insert({contribution[u] - (cost[u] / 2 * leaves[u]), u});
            ++ans;
        }

        cout << ans << endl;
    }

    return 0;
}
