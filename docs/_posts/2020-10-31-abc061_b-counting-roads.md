---
layout: post
mathjax: true
title: Abc061_B Counting Roads
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
int main(void)
{
    int n, m, u, v;
    cin >> n >> m;
    vector<int> deg(n, 0);
    while (m--)
    {
        cin >> u >> v, --u, --v;
        deg[u]++, deg[v]++;
    }
    for_each(deg.begin(), deg.end(), [](int x) { cout << x << endl; });
    return 0;
}

{% endraw %}
```