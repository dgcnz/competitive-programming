---
layout: post
mathjax: true
title: 10006 Carmichael Numbers
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
const int NMAX = 1e7;
bitset<NMAX> is_prime;
vector<int> primes;
void sieve(ll n)
{
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
}
bool is_prime_util(ll n)
{
    if (n < NMAX)
        return is_prime[n];
    for (int i = 0; i < (int)primes.size() and (ll)(primes[i] * primes[i]) <= n;
         ++i)
        if (n % primes[i])
            return false;
    return true;
}
int mod_exp(int base, int exp, int mod)
{
    ll ans;
    if (base == 0)
        return 0;
    if (exp == 0)
        return 1;
    if (exp % 2 == 0)
    {
        ans = mod_exp(base, exp / 2, mod);
        ans = (ans * ans) % mod;
    }
    else
    {
        ans = base % mod;
        ans = (ans * mod_exp(base, exp - 1, mod) % mod) % mod;
    }
    return (int)ans;
}
bool is_carmichael(int n)
{
    for (int a = 2; a <= n - 1; ++a)
    {
        if (mod_exp(a, n, n) != a)
            return false;
    }
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    sieve(NMAX);
    while (cin >> n and n)
    {
        if (not is_prime_util(n) and is_carmichael(n))
            cout << "The number " << n << " is a Carmichael number." << endl;
        else
            cout << n << " is normal." << endl;
    }
}

{% endraw %}
```
