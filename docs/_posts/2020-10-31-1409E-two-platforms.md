---
layout: post
mathjax: true
title: 1409E Two Platforms
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
using pll = pair<ll, ll>;
int const NMAX = 2e5 + 11;
ll n, k;
ll x[NMAX];
pll nsaved(int i)
{
    auto it = upper_bound(x + i, x + n, x[i] + k);
    return make_pair(distance(x + i, it), distance(x, it));
}
ll solve(void)
{
    vector<pll> saved_at(n);
    vector<ll> best_from(n + 1, 0);
    sort(x, x + n);
    for (int i = n - 1; i >= 0; --i)
    {
        saved_at[i] = nsaved(i);
        best_from[i] = max(saved_at[i].first, best_from[i + 1]);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        auto [lans, j] = saved_at[i];
        auto rans = best_from[j];
        ans = max(lans + rans, ans);
    }
    return ans;
}
int main(void)
{
    int t, trash;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> x[i];
        for (int i = 0; i < n; ++i)
            cin >> trash;
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```
