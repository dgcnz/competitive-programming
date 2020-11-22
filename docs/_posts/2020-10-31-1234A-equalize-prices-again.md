---
layout: post
mathjax: true
title: 1234A Equalize Prices Again
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
int main(void)
{
    int t, n, x, s;
    cin >> t;
    while (t--)
    {
        s = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            s += x;
        }
        cout << (int)ceil(s / (n * 1.0)) << endl;
    }
}

{% endraw %}
```