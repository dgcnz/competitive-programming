---
layout: post
mathjax: true
title: 753A - Santa Claus Candies
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
    int n, i;
    int sum = 0;
    cin >> n;
    for (i = 1; sum + i <= n and (n - sum - i) > i; ++i)
        sum += i;
    cout << i - 1 + (sum != n) << endl;
    for (int j = 1; j < i; ++j)
        cout << j << " ";
    if (sum != n)
        cout << n - sum << endl;
    return 0;
}

{% endraw %}
```
</details>

