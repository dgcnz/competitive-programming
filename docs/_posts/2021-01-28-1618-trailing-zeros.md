---
layout: post
mathjax: true
title: 1618 - Trailing Zeros
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
int solve(int n)
{
    if (n == 0)
        return 0;
    return n / 5 + solve(n / 5);
}
int main(void)
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}

{% endraw %}
```
</details>

