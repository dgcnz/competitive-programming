---
layout: post
mathjax: true
title: abc103_c - Modulo Summation
problem_url: https://atcoder.jp/contests/abc103/tasks/abc103_c
tags: modulo, observation, lcm
memory_complexity: O(n)
time_complexity: O(n)
---

Imagine there exist a value $m$ such that it maximizes the contribution of
each term in the summation of $f$, meaning that $m \equiv a_i - 1 \mod a_i$
for all $i$.

If such a value exists, then $m + 1$ must be divisible by all $a_i$. We know
an number with such properties exists, as the lcm of all $a_i$ behaves as an
$m + 1$. Therefore, the answer is:

$$\sum_{i = 1}^n a_i - 1$$


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
ll solve(vi a) { return accumulate(begin(a), end(a), 0LL) - (int)(a).size(); }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << solve(a) << endl;
    return 0;
}

{% endraw %}
```
</details>

