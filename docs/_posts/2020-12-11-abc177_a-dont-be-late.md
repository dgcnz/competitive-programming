---
layout: post
mathjax: true
title: abc177_a - Dont Be Late
problem_url: https://atcoder.jp/contests/abc177/tasks/abc177_a
tags: easy
memory_complexity: O(1)
time_complexity: O(1)
---

To arrive in time, this has to be true:
$$T >= \frac{D}{S}$$


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
    int d, t, s;
    cin >> d >> t >> s;
    cout << (((d + s - 1) / s <= t) ? "Yes" : "No") << endl;
    return 0;
}

{% endraw %}
```
</details>

