---
layout: post
mathjax: true
title: abc133_c - Remainder Minimization 2019
problem_url: https://atcoder.jp/contests/abc133/tasks/abc133_c
tags: modulo, math, observation
memory_complexity: O(1)
time_complexity: O(2019^2)
---

By the pigeonhole principle, note that if $R - L + 1 \geq 2019$, there must
be an $i$, $L \leq i \leq R$ such that $i \equiv 0 \mod 2019$. In such case,
the answer is $0$.

Otherwise, we may brutforce all ordered pairs $(i, j)$ in that range and keep
the minimum. Since the range has length at most $2019$, the number of
computations is order $O(10^6)$, enough for the time limit.


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
int solve(int l, int r)
{
    if (r - l + 1 >= 2019)
        return 0;
    int ans = 2019;
    for (int i = l; i < r; ++i)
        for (int j = i + 1; j <= r; ++j)
            ans = min(ans, ((i % 2019) * (j % 2019)) % 2019);
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int l, r;
    cin >> l >> r;
    cout << solve(l, r) << endl;
    return 0;
}

{% endraw %}
```
</details>

