---
layout: post
mathjax: true
title: Abc048_B Between A And B
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
    ll a, b, x, ap, bp;
    cin >> a >> b >> x;
    ap = (a + x - 1) / x;
    bp = b / x;
    cout << bp - ap + 1 << endl;
    return 0;
}

{% endraw %}
```
</details>

