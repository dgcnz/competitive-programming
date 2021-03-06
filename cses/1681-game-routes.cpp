#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

const int NMAX = 1e5 + 11;
const int MOD  = 1e9 + 7;

int  n, m;
bool visited[NMAX];
vi   g[NMAX], gi[NMAX], vsorted;

int add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }

void toposort(int u)
{
    for (auto v : g[u])
    {
        if (visited[v])
            continue;
        toposort(v);
    }
    visited[u] = true;
    vsorted.push_back(u);
}

int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        gi[v].push_back(u);
    }

    toposort(1);
    reverse(vsorted.begin(), vsorted.end());
    vi dp(n + 1, 0);
    dp[1] = 1;
    for (auto v : vsorted)
    {
        for (auto u : gi[v])
        {
            if (visited[u])
                dp[v] = add((ll)dp[v], (ll)dp[u]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
