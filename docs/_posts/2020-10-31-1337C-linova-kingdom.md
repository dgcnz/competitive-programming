---
layout: post
mathjax: true
title: 1337C Linova Kingdom
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
const int NMAX = 2 * 1e5 + 11;
int n, k, depth[NMAX];
vi g[NMAX], ans;
int dfs(int u, int parent, int depth = 0)
{
    int children = 0;
    for (int v : g[u])
        if (v != parent)
            children += 1 + dfs(v, u, depth + 1);
    ans.push_back(depth - children);
    return children;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int u, v;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    dfs(0, -1);
    sort(ans.rbegin(), ans.rend());
    cout << accumulate(ans.begin(), ans.begin() + k, 0LL) << endl;
    return 0;
}

{% endraw %}
```