---
layout: post
mathjax: true
title: abc174_a - Air Conditioner
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
    int x;
    cin >> x;
    cout << (x >= 30 ? "Yes" : "No") << endl;
    return 0;
}

{% endraw %}
```
</details>

