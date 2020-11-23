---
layout: post
mathjax: true
title: 1360A Minimal Square
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
int main(void)
{
    int t, a, b, ans;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (2 * a > b)
            ans = 2 * a * 2 * a;
        else
            ans = b * b;
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```