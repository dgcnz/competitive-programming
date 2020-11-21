---
layout: post
mathjax: true
title: 439D Devu And His Brother
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
using predicate = function<bool(int)>;
int const NMAX = 1e5 + 11;
int n, m, a[NMAX], b[NMAX];
ll cost(int x)
{
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans += max(a[i], x) - a[i];
    for (int i = 0; i < m; ++i)
        ans += b[i] - min(b[i], x);
    return ans;
}
int bs(int l, int r, predicate p)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (p(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    int x = bs(0, *max_element(b, b + m), [](int x) {
        return (cost(x + 1) - cost(x)) >= 0;
    });
    cout << cost(x) << endl;
    return 0;
}

{% endraw %}
```
