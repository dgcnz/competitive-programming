---
layout: post
mathjax: true
title: 1712 Exponentiation Ii
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
int const MOD = 1e9 + 7;
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
ll modpow(ll a, ll b, ll mod)
{
    a %= mod;
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main(void)
{
    int t, PHI = phi(MOD);
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << modpow(a, modpow(b, c, PHI), MOD) << endl;
    }
    return 0;
}

{% endraw %}
```
