---
layout: post
mathjax: true
title: 1335A Candies Two Sisters
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
ll n;
ll solve(void)
{
    ll ans = n - ceil((n + 1) / 2.0);
    if (ans == n - ans)
        return 0;
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```