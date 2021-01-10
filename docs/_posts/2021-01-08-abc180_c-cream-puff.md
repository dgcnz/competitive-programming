---
layout: post
mathjax: true
title: abc180_c - Cream Puff
problem_url: https://atcoder.jp/contests/abc180/tasks/abc180_c
tags: divisibility, factors, number_theory, implementation
memory_complexity: O(2 \sqrt{n})
time_complexity: O(\sqrt{n} \log{\sqrt{n}})
---

Get factors up to $\sqrt{n}$ (with their co-factors) and print them.


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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;
    set<ll> factors;
    for (ll x = 1, sq = sqrt(n); x <= sq; ++x)
    {
        if (n % x == 0)
        {
            factors.insert(x);
            factors.insert(n / x);
        }
    }
    for (auto x : factors)
        cout << x << endl;
    return 0;
}

{% endraw %}
```
</details>

