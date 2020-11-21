---
layout: post
title: 1144F Graph Without Long Directed Paths
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int const NMAX = 2e5 + 11;
int n, m;
vi g[NMAX];
ii edges[NMAX];
bool color[NMAX];
bool bfs(int src)
{
    queue<int> frontier;
    vector<bool> visited(n + 1, false);
    frontier.push(src);
    color[src] = 1;
    while (not frontier.empty())
    {
        auto u = frontier.front();
        frontier.pop();
        for (auto v : g[u])
        {
            if (not visited[v])
            {
                frontier.push(v);
                color[v] = !color[u];
                visited[v] = true;
            }
            else if (visited[v] and color[v] == color[u])
                return false;
        }
    }
    return true;
}
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = {u, v};
    }
    if (bfs(1))
    {
        cout << "YES" << endl;
        for (int i = 0; i < m; ++i)
        {
            auto [u, v] = edges[i];
            cout << color[u];
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}

```
