---
layout: post
title: 1716 Distributing Apples
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
template <long long M, typename T = long long>
class NumMod
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    T x;
  public:
    NumMod<M, T>(T x) : x(x) {}
    NumMod<M, T>() : x(0) {}
    NumMod<M, T>(NumMod<M, T> &n) : x(n.x) {}
    explicit operator T() const { return x; }
    T v(void) const { return (this->x + M) % M; }
    NumMod<M, T> &operator=(NumMod<M, T> const &y)
    {
        this->x = y.v();
        return *this;
    }
    NumMod<M, T> &operator=(T const &y)
    {
        return this->operator=(NumMod<M, T>(y));
    }
    NumMod<M, T> operator+(NumMod<M, T> y) const { return (v() + y.v()) % M; }
    NumMod<M, T> operator+(T y) const
    {
        return this->operator+(NumMod<M, T>(y));
    }
    NumMod<M, T> operator-(NumMod<M, T> y) const { return (v() - y.v()) % M; }
    NumMod<M, T> operator-(T y) const
    {
        return this->operator-(NumMod<M, T>(y));
    }
    NumMod<M, T> &operator+=(NumMod<M, T> y)
    {
        return this->operator=(operator+(y));
    }
    NumMod<M, T> operator*(NumMod<M, T> y) const { return (v() * y.v()) % M; }
    NumMod<M, T> operator*(T y) const
    {
        return this->operator*(NumMod<M, T>(y));
    }
    NumMod<M, T> &operator*=(NumMod<M, T> y)
    {
        return this->operator=(operator*(y));
    }
    NumMod<M, T> operator/(NumMod<M, T> y)
    {
        return this->operator*(inverse(y));
    }
    NumMod<M, T> inverse(NumMod<M, T> y) { return binpow(y, M - 2); }
};
int const NMAX = 2e6 + 11;
int const MOD = 1e9 + 7;
NumMod<MOD, ll> fact[NMAX];
void precompute_fact(void)
{
    fact[0] = 1;
    for (int i = 1; i < NMAX; ++i)
        fact[i] = fact[i - 1] * i;
}
template <typename T>
T binpow(T a, ll b)
{
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a *= a;
        b >>= 1;
    }
    return res;
}
ll C(ll n, ll k)
{
    if (k > n)
        return 1;
    return ll(fact[n] / (fact[n - k] * fact[k]));
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    precompute_fact();
    ll n, k;
    cin >> n >> k;
    cout << C(n + k - 1, k) << endl;
    return 0;
}

{% endraw %}
```
