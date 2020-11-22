---
layout: post
mathjax: true
title: 1362A Johnny Ancient Computer
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
ll solve(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (a % b != 0)
        return -1;
    ll d = a / b;
    ll e2 = 0;
    while (d != 1)
    {
        if (d % 2 != 0)
            return -1;
        d /= 2;
        ++e2;
    }
    ll ans = 0;
    ans += e2 / 3;
    e2 = e2 % 3;
    ans += e2 / 2;
    e2 = e2 % 2;
    ans += e2;
    return ans;
}
int main(void)
{
    ll t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}

{% endraw %}
```