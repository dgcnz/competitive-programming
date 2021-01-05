---
layout: post
mathjax: true
title: 1471C - Strange Birthday Party
problem_url: https://codeforces.com/contest/1471/problem/C
tags: sorting, greedy
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Assign people with higher default cost, $k_i$, to the presents with lower
cost.


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
ll solve(vi k, vi c)
{
    sort(begin(k), end(k), greater<int>());
    int cur = 0;
    ll ans = 0;
    for (auto &ki : k)
    {
        if (cur < ki)
            ki = cur++;
        ans += c[ki];
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
        int n, m;
        cin >> n >> m;
        vi k(n), c(m);
        for (auto &ki : k)
            cin >> ki, ki--;
        for (auto &ci : c)
            cin >> ci;
        cout << solve(k, c) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

