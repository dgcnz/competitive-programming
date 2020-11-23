---
layout: post
mathjax: true
title: Abc144_C Walk Multiplication Table
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
    ll n;
    cin >> n;
    ll d0 = 1;
    for (int i = 1, m = sqrt(n); i <= m; ++i)
    {
        if (n % i == 0)
        {
            d0 = i;
        }
    }
    cout << d0 + n / d0 - 2 << endl;
    return 0;
}

{% endraw %}
```
</details>

