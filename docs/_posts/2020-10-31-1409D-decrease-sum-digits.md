---
layout: post
title: 1409D Decrease Sum Digits
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
