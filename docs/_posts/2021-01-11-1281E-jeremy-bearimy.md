---
layout: post
mathjax: true
title: 1281E - Jeremy Bearimy
problem_url: https://codeforces.com/contest/1281/problem/E
tags: greedy, dfs, trees
memory_complexity: O(n + m)
time_complexity: O(n + m)
---

[Editorial](https://codeforces.com/blog/entry/72212).


{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using Graph = vector<vector<ii>>;
pair<ll, ll> solve(Graph g)
{
    int n = g.size();
    vector<ll> sz(n, 1), dp1(n, 0), dp2(n, 0);
    function<void(int, int)> dfs;
    dfs = [&](int u, int p) {
        for (auto [v, w] : g[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            sz[u] += sz[v];
            dp1[u] += dp1[v] + (sz[v] & 1 ? w : 0);
            dp2[v] = min(sz[v], n - sz[v]) * w;
        }
    };
    dfs(0, 0);
    return {dp1[0], accumulate(begin(dp2), end(dp2), 0LL)};
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        Graph g(2 * k);
        for (int i = 0; i < 2 * k - 1; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w, u--, v--;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        auto [G, B] = solve(g);
        cout << G << " " << B << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

