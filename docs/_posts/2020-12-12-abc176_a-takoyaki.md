---
layout: post
mathjax: true
title: abc176_a - Takoyaki
problem_url: https://atcoder.jp/contests/abc176/tasks/abc176_a
tags: easy
memory_complexity: O(1)
time_complexity: O(1)
---

The answer is:
$$t \times ceil(\frac{n}{x})$$


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
int ceil(int a, int b) { return (a + b - 1) / b; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, x, t;
    cin >> n >> x >> t;
    cout << t * ceil(n, x) << endl;
    return 0;
}

{% endraw %}
```
</details>

