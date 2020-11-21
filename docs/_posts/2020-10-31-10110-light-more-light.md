---
layout: post
mathjax: true
title: 10110 Light More Light
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
ll count_divisors(ll n)
{
    ll sqrtn = sqrt(n), ans = 0;
    for (ll i = 1; i <= sqrtn; ++i)
        if (n % i == 0)
            ans += 2;
    if (sqrtn * sqrtn == n)
        --ans;
    return ans;
}
int main(void)
{
    ll n;
    string ans[2] = {"no", "yes"};
    while (cin >> n and n != 0)
        cout << ans[count_divisors(n) % 2] << endl;
    return 0;
}

{% endraw %}
```
