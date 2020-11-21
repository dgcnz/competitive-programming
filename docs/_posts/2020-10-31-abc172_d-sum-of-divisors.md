---
layout: post
mathjax: true
title: Abc172_D Sum Of Divisors
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
int const NMAX = 1e7 + 11;
int f[NMAX];
int main(void)
{
    int n;
    cin >> n;
    fill(f, f + n + 1, 2);
    f[1] = 1;
    for (ll i = 2; i <= n; ++i)
    {
        for (ll j = i; j * i <= n; ++j)
        {
            if (i == j)
                f[i * j] += 1;
            else
                f[i * j] += 2;
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i)
    {
        ans += i * f[i];
    }
    cout << ans;
    return 0;
}

{% endraw %}
```
