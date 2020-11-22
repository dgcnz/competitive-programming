---
layout: post
mathjax: true
title: Abc167_B Easy Linear Programming
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
using ll = long long;
ll solve(int a, int b, int c, int k)
{
    ll ans = 0;
    ans += min(a, k);
    k -= min(a, k);
    if (k == 0)
        return ans;
    k -= min(b, k);
    if (k == 0)
        return ans;
    ans -= min(c, k);
    k -= min(c, k);
    return ans;
}
int main(void)
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << solve(a, b, c, k) << endl;
    return 0;
}

{% endraw %}
```