---
layout: post
mathjax: true
title: 263A Beautiful Matrix
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
    int cell, ans = 0;
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            cin >> cell;
            if (cell)
                ans = abs(3 - i) + abs(3 - j);
        }
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```