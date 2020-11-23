---
layout: post
mathjax: true
title: 1391C Cyclic Permutations
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

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int const NMAX = 1e6 + 11;
ll fact[NMAX], inv[NMAX];
void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < NMAX; i++)
        fact[i] = fact[i - 1] * i % MOD;
    inv[1] = 1;
    for (int i = 2; i < NMAX; ++i)
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
}
int extended_gcd(int a, int b, int &x, int &y)
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
ll inverse(int a)
{
    if (a < NMAX)
        return inv[a];
    int x, y;
    int mod = MOD;
    int g = extended_gcd(a, mod, x, y);
    if (g != 1)
    {
        return 0;
    }
    else
    {
        x = (x % MOD + MOD) % MOD;
        return x;
    }
}
ll nck(int n, int k)
{
    return fact[n] * inverse(fact[k]) % MOD * inverse(fact[n - k]) % MOD;
}
ll mult(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int main(void)
{
    int n;
    cin >> n;
    precompute();
    ll ans = fact[n];
    ll cur = 1;
    for (int k = 0; k < n - 1; ++k)
    {
        cur = mult(2, cur);
    }
    cout << sub(ans, cur);
    return 0;
}

{% endraw %}
```
</details>

