---
layout: post
mathjax: true
title: PT07X - Vertex Cover
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



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
using vi = vector<int>;
const int NMAX = 1e5 + 11;
vi g[NMAX];
int dp[NMAX];
void compdp(int u, int p)
{
    dp[u] = 0;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        compdp(v, u);
        if (dp[v] == 0)
            dp[u] = 1;
    }
}
int main(void)
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    compdp(1, 0);
    cout << accumulate(dp + 1, dp + n + 1, 0) << endl;
    return 0;
}

{% endraw %}
```
</details>

