---
layout: post
mathjax: true
title: 1409B Minimum Product
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

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
