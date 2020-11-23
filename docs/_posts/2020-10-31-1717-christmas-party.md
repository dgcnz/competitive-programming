---
layout: post
mathjax: true
title: 1717 Christmas Party
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
using ii = pair<int, int>;
using vi = vector<int>;
template <long long M, typename T = long long>
class NumMod
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    using NM = NumMod<M, T>;
    T x;
  public:
    static const ll MOD = M;
    NumMod(T x) : x(x) {}
    NumMod() : x(0) {}
    NumMod(NM const &y) : x(y.v()) {}
    explicit operator T() const { return x; }
    T v(void) const { return (this->x + M) % M; }
    NM & operator=(NM const &y)
    {
        this->x = y.v();
        return *this;
    }
    NM &operator=(T const &y) { return this->operator=(NM(y)); }
    NM &operator+=(NM const &y) { return this->operator=(operator+(y)); }
    NM &operator-=(NM const &y) { return this->operator=(operator-(y)); }
    NM &operator*=(NM const &y) { return this->operator=(operator*(y)); }
    NM operator+(NM const &y) const { return (v() + y.v()) % M; }
    NM operator+(T const &y) const { return this->operator+(NM(y)); }
    NM operator-(NM const &y) const { return (v() - y.v()) % M; }
    NM operator-(T const &y) const { return this->operator-(NM(y)); }
    NM operator*(NM const &y) const { return (v() * y.v()) % M; }
    NM operator*(T const &y) const { return this->operator*(NM(y)); }
    NM operator/(NM const &y) const { return this->operator*(inverse(y)); }
    NM inverse(NM const &y) const { return binpow(y, M - 2); }
};
int const NMAX = 2e6 + 11;
int const MOD = 1e9 + 7;
using NM = NumMod<MOD, ll>;
NM fact[NMAX];
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
    ll n;
    cin >> n;
    vector<NM> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 0;
    for (int i = 2; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1);
    cout << ll(dp[n]) << endl;
    return 0;
}

{% endraw %}
```
</details>

