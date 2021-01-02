---
layout: post
mathjax: true
title: 793A - Oleg And Shares
problem_url: https://codeforces.com/problemset/problem/793/A
tags: math, implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Let's say that after some number of operations, all numbers become $x$. Note
that $x$ has to be $\min(a_1, a_2,... a_n)$, because it would be suboptimal
otherwise.

So, if all numbers can reach $x$ by decrementing by $k$, then it should be
possible.


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
ll solve(vi a, int k)
{
    int mv = *min_element(begin(a), end(a));
    ll ans = 0;
    for (auto x : a)
    {
        if ((x - mv) % k)
            return -1;
        ans += (x - mv) / k;
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    cout << solve(a, k) << endl;
    return 0;
}

{% endraw %}
```
</details>

