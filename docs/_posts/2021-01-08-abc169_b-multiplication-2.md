---
layout: post
mathjax: true
title: abc169_b - Multiplication 2
problem_url: https://atcoder.jp/contests/abc169/tasks/abc169_b
tags: math, implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Test for $a_i \leq 10^{18} / \text{ans}$.


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
ll solve(vector<ll> a)
{
    if (auto it = find(begin(a), end(a), 0LL); it != a.end())
        return 0LL;
    ll ans = 1, maxv = 1e18;
    for (auto ai : a)
    {
        if (ai <= maxv / ans)
            ans *= ai;
        else
            return -1;
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << solve(a) << endl;
    return 0;
}

{% endraw %}
```
</details>

