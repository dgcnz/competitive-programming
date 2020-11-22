---
layout: post
mathjax: true
title: 1068 Weird Algorithm
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
    long long n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        n = (n % 2 == 0 ? n / 2 : 3 * n + 1);
    }
    cout << n;
    return 0;
}

{% endraw %}
```