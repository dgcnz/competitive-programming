---
layout: post
mathjax: true
title: abc175_c - Walking Takahashi
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
int main(void)
{
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    if (x / d <= k)
    {
        k -= x / d;
        x -= (x / d) * d;
        if (k % 2 == 1)
            x -= d;
    }
    else
    {
        x -= k * d;
        k -= k;
    }
    cout << abs(x) << endl;
    return 0;
}

{% endraw %}
```
</details>

