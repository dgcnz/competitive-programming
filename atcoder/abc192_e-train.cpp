/** @file
 * @date                2021-02-20
 * @url                 https://atcoder.jp/contests/abc192/tasks/abc192_e
 * @tags                graphs, dijkstra, shortest_path
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         15
 * @time_complexity     O(n \log{n} + m)
 * @memory_complexity   O(n)
 * @idea
 * Dijkstra but with a catch. For an edge `(u, v, t, k)` with a shortest
 * distance to `u`, `d[u]`, one can compute the `d[v]` as the smallest multiple of `k`
 * greater than `d[u]` plus the time to traverse the edge, `t`.
 *
 * ```cpp
 * t + k * ceil(d[u] / k)
 * ```
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
T ceil(T a, T b)
{
    return (a + b - 1) / b;
}

template <typename T>
struct Dijkstra
{
    using Graph = vector<vector<tuple<int, T, T>>>;
    T INF       = numeric_limits<T>::max();

    Graph       g;
    int         src, m = 0;
    vector<int> p;
    vector<T>   d;

    Dijkstra(int n) : g(n), p(n), d(n){};

    void add_edge(int u, int v, T t, T k) { g[u].emplace_back(v, t, k); }

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

            for (auto [v, t, k] : g[u])
            {
                T cur = t + k * ceil(d[u], k);
                if (cur < d[v])
                {
                    q.erase({d[v], v});
                    d[v] = cur;
                    p[v] = u;
                    q.emplace(d[v], v);
                }
            }
        }
    }

    void clear(int src)
    {
        this->src = src;
        fill(begin(p), end(p), -1);
        fill(begin(d), end(d), INF);
    }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, x, y;
    cin >> n >> m >> x >> y, x--, y--;

    Dijkstra<ll> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        ll  t, k;
        cin >> u >> v >> t >> k, u--, v--;
        g.add_edge(u, v, t, k);
        g.add_edge(v, u, t, k);
    }

    g.run_sparse(x);
    if (g.p[y] != -1)
        cout << g.d[y] << endl;
    else
        cout << -1 << endl;

    return 0;
}
