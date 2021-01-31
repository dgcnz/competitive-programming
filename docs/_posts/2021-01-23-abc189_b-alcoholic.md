---
layout: post
mathjax: true
title: abc189_b - Alcoholic
problem_url: https://atcoder.jp/contests/abc189/tasks/abc189_b
tags: implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Linearly test if the $i$th liquor gets Takahashi drunk. To avoid precision
errors, multiply $x$ by $100$ instead of dividing each percentage by $100$.


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
int solve(vi v, vi p, ll x)
{
    int n = (int)(v).size();
    ll cur = 0;
    x *= 100;
    for (int i = 0; i < n; ++i)
    {
        cur += v[i] * p[i];
        if (cur > x)
            return i + 1;
    }
    return -1;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vi v(n), p(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i] >> p[i];
    cout << solve(v, p, x);
    return 0;
}

{% endraw %}
```
</details>

