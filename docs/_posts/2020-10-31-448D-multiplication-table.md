---
layout: post
mathjax: true
title: 448D Multiplication Table
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using predicate = function<bool(ll)>;
ll n, m, k;
ll n_smaller(ll x)
{
    ll ans = 0;
    for (int row = 1; row <= n; ++row)
        ans += min((x - 1) / row, m);
    return ans;
}
ll bs(ll lo, ll hi, predicate p)
{
    while (lo < hi)
    {
        ll mid = lo + (hi - lo + 1) / 2;
        if (p(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}
int main(void)
{
    cin >> n >> m >> k;
    cout << bs(1, 1e12, [](ll x) { return n_smaller(x) < k; }) << endl;
    return 0;
}

{% endraw %}
```
