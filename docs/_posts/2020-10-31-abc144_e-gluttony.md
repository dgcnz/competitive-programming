---
layout: post
mathjax: true
title: Abc144_E Gluttony
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

```cpp
{% raw %}
using namespace std;
using ll = long long;
using predicate = function<bool(ll)>;
int const NMAX = 2e5 + 11;
ll n, k, a[NMAX], f[NMAX];
bool ok(ll x)
{
    ll tk = k;
    for (int i = 0; i < n; ++i)
    {
        tk -= max((ll)0, a[i] - x / f[i]);
        if (tk < 0)
            return false;
    }
    return true;
}
ll bs(ll l, ll r, predicate p)
{
    while (l < r)
    {
        ll m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}
int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> f[i];
    sort(a, a + n);
    sort(f, f + n, greater<int>());
    cout << bs(0, 1e12 + 11, ok) << endl;
    return 0;
}

{% endraw %}
```