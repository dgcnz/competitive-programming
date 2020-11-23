---
layout: post
mathjax: true
title: 461A Appleman And Toastman
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
</details>

