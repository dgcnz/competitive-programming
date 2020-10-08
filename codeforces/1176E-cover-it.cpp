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

int n, m;
vi  g[NMAX], parity[2];

void bfs(int src)
{
    vi         visited(n + 1, false), dist(n + 1, 0);
    queue<int> frontier;
    visited[src] = true;
    frontier.push(src);

    dist[src] = 0;
    parity[0].push_back(src);
    while (not frontier.empty())
    {
        auto u = frontier.front();
        frontier.pop();

        for (auto v : g[u])
        {
            if (not visited[v])
            {
                dist[v] = dist[u] + 1;
                parity[dist[v] % 2].push_back(v);
                visited[v] = true;
                frontier.push(v);
            }
        }
    }
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; ++i)
            g[i].clear();
        parity[0].clear(), parity[1].clear();

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        bfs(1);

        int ix = 1;
        if (isz(parity[0]) < isz(parity[1]))
            ix = 0;
        cout << isz(parity[ix]) << endl;
        for (auto u : parity[ix])
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
