---
layout: post
mathjax: true
title: 1409A Yet Another Two Integers
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

```cpp
{% raw %}
using namespace std;
using ll = long long;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll diff = abs(b - a);
        ll ans = diff / 10 + ((diff % 10) > 0);
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```