---
layout: post
mathjax: true
title: abc181_b - Trapezoid Sum
problem_url: https://atcoder.jp/contests/abc181/tasks/abc181_b
tags: math, easy
memory_complexity: O(1)
time_complexity: O(n)
---

Each operation $a, b$, is equivalent to increasing the answer by $sq(b) -
sq(a)$, where $sq(n)$ is the sum of the first $n$ natural numbers.


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
ll sq(ll n) { return (n * (n + 1)) / 2; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        ans += sq(b) - sq(a - 1);
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

