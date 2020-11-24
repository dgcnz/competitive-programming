---
layout: post
mathjax: true
title: 236B - Easy Number Challenge
problem_url: https://codeforces.com/contest/236/problem/B
tags: number_theory, divisors, brute_force
memory_complexity: O(abc)
time_complexity: O(abc * \log{abc})
---

- Precompute the divisor function up to $a \times b \times c$.
- A way to interpret this is the following: For each possible number, we'll
increment the divisor count of all its multiples.
- Brute-force the solution.


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
using vi = vector<int>;
vi precompute_divisors(int n)
{
    vi d(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            d[j]++;
    return d;
}
int solve(int a, int b, int c)
{
    int const MOD = 1 << 30;
    ll ans = 0;
    auto d = precompute_divisors(a * b * c);
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            for (int k = 1; k <= c; ++k)
                ans = (ans + d[i * j * k]) % MOD;
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
    return 0;
}

{% endraw %}
```
</details>

