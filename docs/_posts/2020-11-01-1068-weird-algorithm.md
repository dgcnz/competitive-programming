---
layout: post
mathjax: true
title: 1068 Weird Algorithm
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
</details>

