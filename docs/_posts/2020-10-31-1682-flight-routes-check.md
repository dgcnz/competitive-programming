---
layout: post
mathjax: true
title: 1682 Flight Routes Check
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
const int NMAX = 1e5 + 11;
int n, m, x, y, visited[NMAX];
vi g[NMAX], gi[NMAX];
void dfs(int u, const vi gr[], int vval)
{
    visited[u] = vval;
    for (auto v : gr[u])
        if (visited[v] != vval)
            dfs(v, gr, vval);
}
bool vis_check(int vval, int &ans)
{
    for (int u = 1; u <= n; ++u)
    {
        if (visited[u] != vval)
        {
            ans = u;
            return false;
        }
    }
    return true;
}
bool solve(void)
{
    int vval;
    dfs(1, g, vval = 1), x = 1;
    if (not vis_check(vval, y))
        return false;
    dfs(1, gi, vval = 2), y = 1;
    if (not vis_check(vval, x))
        return false;
    return true;
}
int main(void)
{
    int u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        gi[v].push_back(u);
    }
    if (solve())
        cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
        cout << x << " " << y;
    }
    return 0;
}

{% endraw %}
```
