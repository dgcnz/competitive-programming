---
layout: post
mathjax: true
title: 1680 Longest Flight Route
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
int n, m;
bool visited[NMAX];
vi g[NMAX], gi[NMAX], vsorted;
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
    if (not visited[n])
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        reverse(vsorted.begin(), vsorted.end());
        vi dp(n + 1, 0), pre(n + 1, 0), ans;
        for (auto v : vsorted)
        {
            for (auto u : gi[v])
            {
                if (visited[u] and dp[u] + 1 > dp[v])
                {
                    dp[v] = dp[u] + 1;
                    pre[v] = u;
                }
            }
        }
        cout << dp[n] + 1 << endl;
        int u = n;
        do
        {
            ans.push_back(u);
            u = pre[u];
        } while (pre[u]);
        ans.push_back(u);
        for_each(ans.rbegin(), ans.rend(), [](int x) { cout << x << " "; }),
            cout << endl;
    }
    return 0;
}

{% endraw %}
```
