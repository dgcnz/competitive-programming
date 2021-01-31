---
layout: post
mathjax: true
title: keyence2021_a - Two Sequences 2
problem_url: https://atcoder.jp/contests/keyence2021/tasks/keyence2021_c
tags: data_structures, segment_tree, greedy
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Disclaimer: I was sleepy and segtree was the first thing that came to my
mind, don't judge me :(.

Observations:
- For each $c_k$ we have two options. Either we pick $1 \leq i \leq j < k$
(which is $c_{i - 1}$) or we pick $b_j$ ($j = k$) and pair it with the
maximum $a_i$, $1 \leq i \leq j$.

We can code a straightforward greedy with this.


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
using vll = vector<ll>;
using S = ll;
S op(S a, S b) { return max(a, b); }
S e() { return -1; }
vll solve(vll a, vll b)
{
    int n = (int)(a).size();
    vll c(n);
    c[0] = a[0] * b[0];
    using RMQ = atcoder::segtree<S, op, e>;
    RMQ st(a);
    for (int i = 1; i < n; ++i)
        c[i] = max(c[i - 1], b[i] * st.prod(0, i + 1));
    return c;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vll a(n), b(n);
    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;
    auto c = solve(a, b);
    for (auto ci : c)
        cout << ci << endl;
    return 0;
}

{% endraw %}
```
</details>

