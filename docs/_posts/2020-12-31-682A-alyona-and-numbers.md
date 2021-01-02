---
layout: post
mathjax: true
title: 682A - Alyona And Numbers
problem_url: https://codeforces.com/problemset/problem/682/A
tags: math, modulo
memory_complexity: O(\max(n, m))
time_complexity: O(1)
---

So, we must pair numbers with remainder $x$ with those with remainder $5-x$,
$\mod 5$. Since I'm lazy I just precomputed such counts in $O(\max(n, m))$.



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
ll solve(int n, int m)
{
    vi nrem(5, 0), mrem(5, 0);
    for (int i = 1; i <= max(n, m); ++i)
    {
        int rem = i % 5;
        if (i <= n)
            nrem[rem]++;
        if (i <= m)
            mrem[rem]++;
    }
    ll ans = 0;
    for (int i = 0; i < 5; ++i)
        ans += ll(nrem[i]) * ll(mrem[(5 - i) % 5]);
    return ans;
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

