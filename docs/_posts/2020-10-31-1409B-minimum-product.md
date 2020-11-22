---
layout: post
mathjax: true
title: 1409B Minimum Product
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
using ll = long long;
pair<ll, ll> op(ll a, ll x, ll n)
{
    ll p = max(a - n, x);
    n = n - (a - p);
    return {p, n};
}
ll simulate(ll a, ll b, ll x, ll y, ll n)
{
    auto [ap, np1] = op(a, x, n);
    a = ap, n = np1;
    auto [bp, np2] = op(b, y, n);
    b = bp, n = np2;
    return a * b;
}
int main(void)
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll ans0 = simulate(a, b, x, y, n);
        ll ans1 = simulate(b, a, y, x, n);
        cout << min(ans0, ans1) << endl;
    }
    return 0;
}

{% endraw %}
```