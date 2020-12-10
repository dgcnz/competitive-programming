---
layout: post
mathjax: true
title: arc076_a - Reconciled
problem_url: https://atcoder.jp/contests/abc065/tasks/arc076_a
tags: math, sorting
memory_complexity: O(n)
time_complexity: O(n)
---

Note that if $|n - m| > 1$ there's no way to avoid getting two animals of the
same type beside each other.

Without loss of generality, assume $n \geq m$. Let's break it into cases:

1. $ n = m + 1 $: Our arrangements will have the form: $DMDM...MDMD$. We can
count all possible arrangements of dogs $D$ and monkeys $M$ and multiply
those counts together. Since animals are distinguishable, such quantities are
$n!$ and $m!$.
2. $n = m$: Our arrangements will have the form: $DMD...MDM$ or $MDMD...MD$.
Similar arguments, but multiply by $2$ to account for both types of
arrangements.

Since $n$ is small enough, let's just precompute all.


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
int const MOD = 1e9 + 7;
int solve(int n, int m)
{
    if (n < m)
        swap(n, m);
    if (n - m > 1)
        return 0;
    vector<ll> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = (i * fact[i - 1]) % MOD;
    return ((n == m ? 2 : 1) * (fact[n] * fact[m]) % MOD) % MOD;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
    return 0;
}

{% endraw %}
```
</details>

