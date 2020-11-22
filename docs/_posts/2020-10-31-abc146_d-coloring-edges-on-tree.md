---
layout: post
mathjax: true
title: Abc146_D Coloring Edges On Tree
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
using ii = pair<int, int>;
using vii = vector<ii>;
int const NMAX = 1e5 + 11;
int n, ncolors, color[NMAX];
vii g[NMAX];
void dfs(int u, int p = -1, int c = -1)
{
    int free_color = 1;
    for (auto [v, i] : g[u])
    {
        if (v == p)
            continue;
        if (free_color == c)
            ++free_color;
        color[i] = free_color;
        dfs(v, u, free_color);
        ++free_color;
    }
    ncolors = max(ncolors, free_color - 1);
}
int main(void)
{
    int u, v;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v, u--, v--;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    dfs(1);
    cout << ncolors << endl;
    for (int i = 0; i < n - 1; ++i)
        cout << color[i] << endl;
    return 0;
}

{% endraw %}
```