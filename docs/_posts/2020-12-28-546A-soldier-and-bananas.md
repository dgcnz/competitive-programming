---
layout: post
mathjax: true
title: 546A - Soldier And Bananas
problem_url: https://codeforces.com/problemset/problem/546/A
tags: easy, summation
memory_complexity: O(1)
time_complexity: O(1)
---

Reduce summation to closed form and solve the equation.


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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int k, n, w;
    cin >> k >> n >> w;
    int x = max(k * (w * (w + 1)) / 2 - n, 0);
    cout << x << endl;
    return 0;
}

{% endraw %}
```
</details>

