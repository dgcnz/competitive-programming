---
layout: post
mathjax: true
title: 1392C Omkar Waterslide
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
int const NMAX = 2e5 + 11;
ll n, a[NMAX];
ll solve(void)
{
    int i = n - 1;
    ll ans = 0;
    while (i > 0)
    {
        int j = i;
        while (j > 0 and a[j] >= a[j - 1])
            --j;
        if (j > 0)
        {
            ans += (a[j - 1] - a[j]);
            a[j] = a[j - 1];
        }
        i = j;
    }
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```
