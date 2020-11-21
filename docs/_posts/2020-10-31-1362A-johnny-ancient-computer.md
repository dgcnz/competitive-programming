---
layout: post
title: 1362A Johnny Ancient Computer
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
ll solve(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (a % b != 0)
        return -1;
    ll d = a / b;
    ll e2 = 0;
    while (d != 1)
    {
        if (d % 2 != 0)
            return -1;
        d /= 2;
        ++e2;
    }
    ll ans = 0;
    ans += e2 / 3;
    e2 = e2 % 3;
    ans += e2 / 2;
    e2 = e2 % 2;
    ans += e2;
    return ans;
}
int main(void)
{
    ll t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}

```
