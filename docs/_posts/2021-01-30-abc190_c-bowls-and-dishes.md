---
layout: post
mathjax: true
title: abc190_c - Bowls And Dishes
problem_url: https://atcoder.jp/contests/abc190/tasks/abc190_c
tags: bitmasks, brute_force
memory_complexity: O(n + m)
time_complexity: O(2^k (n + m))
---

Let's iterate over all possible configurations of dishes and pick the one
which fulfills the most conditions.

Since $k \leq 16$ we can do this by defining a bitmask where:
- $b(i, j)$ : if $j = 0$,  $c_i$ is taken, if $j = 0$, then $d_i$ is taken.


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
using ii = array<int, 2>;
using vi = vector<int>;
ll solve(vector<ii> conditions, vector<ii> options, int n)
{
    int k = options.size();
    vector<int> balls(n);
    ll ans = 0;
    for (int mask = 0; mask < (1 << k); ++mask)
    {
        fill(begin(balls), end(balls), 0);
        for (int i = 0; i < k; ++i)
        {
            int j = (mask >> i) & 1;
            balls[options[i][j]]++;
        }
        ll cur = 0;
        for (auto [u, v] : conditions)
            cur += balls[u] && balls[v];
        ans = max(ans, cur);
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ii> conditions(m);
    for (auto &[u, v] : conditions)
        cin >> u >> v, u--, v--;
    int k;
    cin >> k;
    vector<ii> options(k);
    for (auto &[u, v] : options)
        cin >> u >> v, u--, v--;
    cout << solve(conditions, options, n) << endl;
    return 0;
}

{% endraw %}
```
</details>

