---
layout: post
mathjax: true
title: Abc172_D Sum Of Divisors
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