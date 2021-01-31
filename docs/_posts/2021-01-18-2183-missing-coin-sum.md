---
layout: post
mathjax: true
title: 2183 - Missing Coin Sum
problem_url: https://cses.fi/problemset/task/2183
tags: greedy, sorting, constructive
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Let's sort the elements in non-decreasing order and iterate them from
smallest to largest.

While considering element $a_i$, assume that we can create all numbers
$1, 2, ..., x$, where $x$ is $\sum_{j = 1}^{i -1}a_j$. Note that by
considering $a_i$, we can construct numbers $a_i, a_i + 1, ..., x + a_i$.
Therefore, only if $x + 1 - a_i \leq 1$  would number $x + 1$ be possible to
construct. Otherwise, the smallest impossible coin sum is $x + 1$.



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
ll solve(vi a)
{
    sort(begin(a), end(a));
    ll sum = 0;
    for (auto ai : a)
    {
        if (ai > sum + 1)
            return sum + 1;
        sum += ai;
    }
    return sum + 1;
}
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

