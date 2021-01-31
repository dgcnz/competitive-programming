/** @file
 * @date                2021-01-28
 * @url                 https://codeforces.com/problemset/problem/20/C
 * @tags                math, sorting
 * @status              AC
 * @score               3
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         20
 * @time_complexity     O((n + m) \log{n})
 * @memory_complexity   O(n + m)
 * @idea
 * Yes, dijkstra.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename T>
struct Dijkstra
{
    using Graph = vector<vector<pair<int, T>>>;
    T INF       = numeric_limits<T>::max();

    Graph       g;
    int         src, m = 0;
    vector<int> p;
    vector<T>   d;

    Dijkstra(int n) : g(n), p(n), d(n){};
    void add_edge(int u, int v, T w = 1) { g[u].emplace_back(v, w), m++; }

    void run_dense(int src = 0)
    {
        clear(src);

        int          n = g.size();
        vector<bool> vis(n, false);
        d[src] = 0;
        for (int i = 0; i < n; i++)
        {
            int u = -1;
            for (int v = 0; v < n; v++)
                if (not vis[v] and (u == -1 or d[v] < d[u]))
                    u = v;

            if (d[u] == INF)
                break;

            vis[u] = true;
            for (auto [v, w] : g[u])
            {
                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    p[v] = u;
                }
            }
        }
    }

    void run_sparse(int src = 0)
    {
        clear(src);

        set<pair<T, int>> q;
        d[src] = 0;
        q.emplace(d[src], src);
        while (!q.empty())
        {
            int u = q.begin()->second;
            q.erase(q.begin());

            for (auto [v, w] : g[u])
            {
                if (d[u] + w < d[v])
                {
                    q.erase({d[v], v});
                    d[v] = d[u] + w;
                    p[v] = u;
                    q.emplace(d[v], v);
                }
            }
        }
    }

    vector<vector<pair<int, T>>> shortest_path_DAG(void) const
    {
        int                          n = g.size();
        vector<vector<pair<int, T>>> dag(n);
        for (int v = 0; v < n; ++v)
            if (auto u = p[v]; u != -1)
                dag[u].emplace_back(v, d[v] - d[u]);
        return dag;
    }

    vector<int> shortest_path(int u) const
    {
        if (d[u] == INF)
            return {};
        vector<int> path;

        for (int v = u; v != src; v = p[v])
            path.push_back(v);
        path.push_back(src);

        reverse(begin(path), end(path));
        return path;
    }
    void clear(int src)
    {
        this->src = src;
        fill(begin(p), end(p), -1);
        fill(begin(d), end(d), INF);
    }
    void operator()(int src = 0)
    {
        long long n = g.size();
        if (n * n + m < (n + m) * log2(n))
            run_dense(src);
        else
            run_sparse(src);
    }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    Dijkstra<ll> dijkstra(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        dijkstra.add_edge(u, v, ll(w));
        dijkstra.add_edge(v, u, ll(w));
    }

    dijkstra(0);
    if (auto ans = dijkstra.shortest_path(n - 1); not ans.empty())
    {
        for (auto x : ans)
            cout << x + 1 << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}
