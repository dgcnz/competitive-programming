---
layout: post
mathjax: true
title: 1094 - Increasing Array
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
const int NMAX = 2e5 + 11;
int a[NMAX];
int main(void)
{
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        ans += max(0, a[i - 1] - a[i]);
        a[i] = max(a[i - 1], a[i]);
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

