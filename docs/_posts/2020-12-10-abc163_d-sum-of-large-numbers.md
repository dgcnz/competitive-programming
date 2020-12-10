---
layout: post
mathjax: true
title: abc163_d - Sum Of Large Numbers
problem_url: https://atcoder.jp/contests/abc163/tasks/abc163_d
tags: math, counting
memory_complexity: O(1)
time_complexity: O(n)
---

I'm kinda lazy to explain this problem, so here's the
[editorial](https://img.atcoder.jp/abc163/editorial.pdf)

Anyhow, the key points are:
- Fix the quantity of numbers to sample, $i$, $k \leq i \leq n + 1$.
- Note that we can produce any number in between the minimum and maximum sum
of $i$ numbers.
- For each desired $i$ compute the size of the range described above.
- Note that those ranges do not overlap.


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
int const MOD = 1e9 + 7;
ll sq(ll n) { return (n * (n + 1)) / 2; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = k; i <= n + 1; ++i)
    {
        ans += sq(n) - sq(n - i) - sq(i - 1) + 1;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

