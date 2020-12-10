---
layout: post
mathjax: true
title: arc102_a - Triangular Relationship
problem_url: https://atcoder.jp/contests/arc102/tasks/arc102_a
tags: counting
memory_complexity: O(1)
time_complexity: O(n)
---

The key insight is to think about the remainders of $a, b, c$ when divided by
$k$.

Trivially, picking $a, b, c$'s with remainder $0$ will yield multiples
of $k$ when added. However, when $k$ is even, we may also count numbers with
remainder $k / 2$.

Note that no other numbers will contribute to the answer.


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
ll solve(int n, int k)
{
    auto ways = [](ll n) -> ll { return n * n * n; };
    ll mid = 0, zero = 0;
    for (int i = 1; i <= n; ++i)
    {
        mid += (k % 2 == 0 and i % k == (k / 2));
        zero += (i % k == 0);
    }
    return ways(zero) + ways(mid);
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}

{% endraw %}
```
</details>

