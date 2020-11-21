---
layout: post
mathjax: true
title: 1316A Grade Allocation
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
ll n, m;
ll a[1010];
ll sum;
ll solve(void)
{
    sum = accumulate(a, a + n, 0);
    ll a0 = min(sum, m);
    return a0;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```
