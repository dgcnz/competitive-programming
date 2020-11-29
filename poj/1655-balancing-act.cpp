#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
typedef long long      ll;
typedef pair<int, int> ii;
typedef vector<int>    vi;

int const NMAX = 2e4 + 11;

int n, sz[NMAX];
vi  g[NMAX];

void calc_sz(int u, int p)
{
    sz[u] = 1;
    for (int i = 0; i < isz(g[u]); ++i)
    {
        int v = g[u][i];
        if (v == p)
            continue;
        calc_sz(v, u);
        sz[u] += sz[v];
    }
}

ii find_centroid(int u, int p)
{
    int balance = n - sz[u];
    for (int i = 0; i < isz(g[u]); ++i)
    {
        int v = g[u][i];
        if (v == p)
            continue;
        if (2 * sz[v] > n or (2 * sz[v] == n and v < u))
            return find_centroid(v, u);
        balance = max(balance, sz[v]);
    }
    return make_pair(u, balance);
}

void reset(void)
{
    for (int i = 0; i <= n; ++i)
    {
        g[i].clear();
        sz[i] = 0;
    }
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        reset();

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        calc_sz(1, 0);
        // dbg(sz);
        ii ans = find_centroid(1, 0);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}
