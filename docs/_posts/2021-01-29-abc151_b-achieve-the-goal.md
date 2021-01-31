---
layout: post
mathjax: true
title: abc151_b - Achieve The Goal
problem_url: https://atcoder.jp/contests/abc151/tasks/abc151_b
tags: math, easy
memory_complexity: O(n)
time_complexity: O(n)
---

Let $x$ be the score needed to achieve a total of $M$ points.

$x = M * N  - \sum_{1}^{n - 1} a_i$

If $x <= k$ then it's achievable, otherwise it's not.


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
ll ceil(ll a, ll b) { return (a + b - 1) / b; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k, m;
    cin >> n >> k >> m;
    vi a(n - 1);
    for (auto &ai : a)
        cin >> ai;
    ll sum = accumulate(begin(a), end(a), 0LL);
    ll x = max(m * n - sum, 0LL);
    x = x > k ? -1 : x;
    cout << x << endl;
    return 0;
}

{% endraw %}
```
</details>

