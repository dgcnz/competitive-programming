---
layout: post
mathjax: true
title: 1409D Decrease Sum Digits
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
int dsum(ll n)
{
    int sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
ll make_zero(ll n, int i)
{
    int j = i;
    while (i--)
    {
        n /= 10;
    }
    n += 1;
    while (j--)
    {
        n *= 10;
    }
    return n;
}
ll solve(ll n, ll s)
{
    ll ans = 0, i = 1;
    while (dsum(n) > s)
    {
        ll cur = make_zero(n, i);
        ans += (cur - n);
        n = cur;
        ++i;
    }
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, s;
        cin >> n >> s;
        cout << solve(n, s) << endl;
    }
    return 0;
}

{% endraw %}
```