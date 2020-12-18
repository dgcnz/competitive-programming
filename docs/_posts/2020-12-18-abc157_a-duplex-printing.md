---
layout: post
mathjax: true
title: abc157_a - Duplex Printing
problem_url: https://atcoder.jp/contests/abc157/tasks/abc157_a
tags: easy
memory_complexity: O(1)
time_complexity: O(1)
---

You need $\frac{(n + 1)}{2}$ pages.


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
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    cout << (n + 1) / 2 << endl;
    return 0;
}

{% endraw %}
```
</details>

