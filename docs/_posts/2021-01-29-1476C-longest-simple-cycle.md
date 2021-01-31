---
layout: post
mathjax: true
title: 1476C - Longest Simple Cycle
problem_url: https://codeforces.com/contest/1476/problem/C
tags: greedy
memory_complexity: O(n)
time_complexity: O(n)
---

We'll denote a cycle's length as the number of nodes it traverses.

Observations:
1. when $a_i = b_i$, the $i-1$ chain necesarily divides the graph into two
parts. The longest cycle cannot go through $i-1$.

We'll scan from left to right and compute the maximum length cycle that ends
at position $i$.

We'll also keep the length of the longest non-closed cycle up to $i$, call it
$open_i$.

Using this two informations, we can check for the following for each $i$:
1. The answer is $open_{i - 1}$ + the length of the $i$th chain, $c_i$,
closing the cycle.
2. $open_i$ will be the maximum between the length of the current chain,
$c_i$, and $c_{i - 1} + 2$.



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
ll solve(vector<ll> a, vector<ll> b, vector<ll> c)
{
    int n = c.size();
    vector<ll> w(n);
    for (int i = 0; i < n - 1; ++i)
        w[i] = abs(a[i + 1] - b[i + 1]) + 1;
    w[n - 1] = c[n - 1];
    ll ans = 0, cur = w[0];
    for (int i = 1; i < n; ++i)
    {
        ans = max(ans, cur + c[i]);
        cur = w[i] == 1 ? 1 : max(w[i], cur + c[i] - w[i] + 2);
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n), b(n), c(n);
        for (auto &ci : c)
            cin >> ci;
        for (auto &ai : a)
            cin >> ai;
        for (auto &bi : b)
            cin >> bi;
        cout << solve(a, b, c) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

