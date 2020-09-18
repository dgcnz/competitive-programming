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

int const NMAX = 2e5 + 11;

int n;
vi  g[NMAX];

ii dfs(int u, int p, int d)
{
    ii ans = {d, u};
    for (auto v : g[u])
    {
        if (v == p)
            continue;

        ans = max(ans, dfs(v, u, d + 1));
    }
    return ans;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto [d1, u] = dfs(1, 0, 0);
    auto [d2, v] = dfs(u, 0, 0);

    cout << d2 << endl;

    return 0;
}
