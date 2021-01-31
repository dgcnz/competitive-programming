---
layout: post
mathjax: true
title: dpD - Knapsack 1
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
using ll = long long;
const int NMAX = 1e2 + 11;
const int WMAX = 1e5 + 11;
int n, c, w[NMAX], v[NMAX];
ll mem[NMAX][WMAX];
bool vis[NMAX][WMAX];
ll dp(int i, int cl)
{
    ll &ans = mem[i][cl];
    if (i == n)
        return 0;
    if (vis[i][cl])
        return mem[i][cl];
    vis[i][cl] = true;
    ans = 0;
    if (cl - w[i] >= 0)
        ans = dp(i + 1, cl - w[i]) + v[i];
    return (ans = max(ans, dp(i + 1, cl)));
}
int main(void)
{
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> v[i];
    cout << dp(0, c) << endl;
    return 0;
}

{% endraw %}
```
</details>

