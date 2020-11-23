---
layout: post
mathjax: true
title: Abc170_C Forbidden List
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
int main(void)
{
    int x, n, y;
    cin >> x >> n;
    set<int> p;
    for (int i = 0; i < n; ++i)
    {
        cin >> y;
        p.insert(y);
    }
    for (int i = 0; i < x + 1; ++i)
    {
        for (auto dir : {-1, +1})
        {
            y = x + dir * i;
            if (p.find(y) == p.end())
            {
                cout << y << endl;
                return 0;
            }
        }
    }
    return 0;
}

{% endraw %}
```
</details>

