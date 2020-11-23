---
layout: post
mathjax: true
title: 1203C Common Divisors
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



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
const int NMAX = 4e5 + 11;
ll n, a[NMAX];
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
ll solve(void)
{
    ll ngcd = a[0], ans = 0;
    for (int i = 1; i < n; ++i)
        ngcd = gcd(ngcd, a[i]);
    for (ll i = 1; i <= sqrt(ngcd); ++i)
    {
        if (ngcd % i == 0)
        {
            if (ngcd / i == i)
                ++ans;
            else
                ans += 2;
        }
    }
    return ans;
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```
</details>

