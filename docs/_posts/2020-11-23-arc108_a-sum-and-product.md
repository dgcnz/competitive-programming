---
layout: post
mathjax: true
title: arc108_a - Sum And Product
problem_url: https://atcoder.jp/contests/arc108/tasks/arc108_a
tags: math, brute_force
memory_complexity: O(1)
time_complexity: O( \sqrt{ \max(S, P)})
---

- Write both equations in terms of one variable, N or M: $N^2 - NS + P = 0$.
- The problem reduces to finding a positive root of that expression.
- This problem could be solved by doing a binary search, but it would result
in integer overflow.
- Note, however, that $\max(N, M) <= \sqrt{max(S, P)}$.
- Since that value doesn't exceed $10^6$, we can linear search the answer.


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
using predicate = function<bool(ll)>;
bool solve(ll S, ll P)
{
    for (ll N = 1, MAX = 1e6; N <= MAX; ++N)
        if (N * (S - N) == P)
            return true;
    return false;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll S, P;
    cin >> S >> P;
    cout << (solve(S, P) ? "Yes" : "No") << endl;
    return 0;
}

{% endraw %}
```
</details>

