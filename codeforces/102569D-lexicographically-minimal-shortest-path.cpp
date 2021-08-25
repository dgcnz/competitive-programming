#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using Edge = pair<int, char>;

template <typename Edge_T>
using Graph = vector<vector<Edge_T>>;

pair<vi, string> solve(Graph<Edge> &g)
{
    int         n   = g.size();
    int const   INF = 1e9;
    vector<int> dist(n, INF);

    [&](int src) {
        vector<int>         p(n, -1);
        set<pair<int, int>> q;
        dist[src] = 0;
        q.emplace(dist[src], src);
        while (!q.empty())
        {
            int u = q.begin()->second;
            q.erase(q.begin());

            for (auto [v, w] : g[u])
            {
                if (dist[u] + 1 < dist[v])
                {
                    q.erase({dist[v], v});
                    dist[v] = dist[u] + 1;
                    p[v]    = u;
                    q.emplace(dist[v], v);
                }
            }
        }
    }(n - 1);

    vector<int>  parent(n, -1);
    vector<char> label(n);
    {
        queue<int> q;
        q.emplace(0);
        parent[0] = 0;

        while (not q.empty())
        {
            char                         minc = 'z' + 1;
            queue<tuple<char, int, int>> frontier;
            while (not q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto [v, c] : g[u])
                    if (dist[v] == dist[u] - 1)
                        frontier.emplace(c, u, v), minc = min(c, minc);
            }

            while (not frontier.empty())
            {
                auto [c, u, v] = frontier.front();
                frontier.pop();
                if (c == minc and parent[v] == -1)
                {
                    q.push(v);
                    parent[v] = u;
                    label[v]  = c;
                }
            }
        }
    }

    int    k = dist[0];
    int    x = n - 1;
    string labels(k, ' ');
    vi     vertices(k + 1);
    for (int i = 0; i < k; ++i)
    {
        labels[i]   = label[x];
        vertices[i] = x;
        x           = parent[x];
    }
    vertices[k] = 0;
    reverse(all(vertices));
    reverse(all(labels));
    return {vertices, labels};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    Graph<Edge> g(n);
    for (int i = 0; i < m; ++i)
    {
        int  u, v;
        char c;
        cin >> u >> v >> c, u--, v--;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    auto [p, str] = solve(g);
    cout << str.size() << endl;
    transform(all(p), begin(p), [](int x) { return x + 1; });
    write(all(p), " "), cout << endl;
    cout << str << endl;

    return 0;
}
