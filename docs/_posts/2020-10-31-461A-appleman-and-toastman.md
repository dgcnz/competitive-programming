---
layout: post
mathjax: true
title: 461A Appleman And Toastman
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
int n;
int a[300010];
ll solve(void)
{
    ll ans = 0;
    ll w = 2;
    sort(a, a + n);
    for (int i = 0; i < n - 1; ++i)
    {
        ans += w * a[i];
        ++w;
    }
    return ans + (w - 1) * a[n - 1];
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```