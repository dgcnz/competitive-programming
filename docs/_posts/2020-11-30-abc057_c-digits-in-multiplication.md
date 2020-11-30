---
layout: post
mathjax: true
title: abc057_c - Digits In Multiplication
problem_url: https://atcoder.jp/contests/abc057/tasks/abc057_c
tags: number_theory, divisors
memory_complexity: O(1)
time_complexity: O(\sqrt{n})
---

Brute-force up to $\sqrt{n}$.


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
    int ans = 64;
    for (int i = 1, m = sqrt(n); i <= m; ++i)
        if (n % i == 0)
            ans = min(ans, 1 + (int)log10(n / i));
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

