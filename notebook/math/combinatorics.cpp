#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <int M, typename T = long long>
class NumMod
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    using NM = NumMod<M, T>;
    T x;

  public:
    static const int MOD = M;

    NumMod(T x) : x(x) {}
    NumMod() : x(0) {}
    NumMod(NM const &y) : x(y.v()) {}
    explicit operator T() const { return x; }
    T        v(void) const { return (this->x + M) % M; }
    NM &     operator=(NM const &y)
    {
        this->x = y.v();
        return *this;
    }
    NM &operator=(T const &y) { return this->operator=(NM(y)); }
    NM &operator+=(NM const &y) { return this->operator=(operator+(y)); }
    NM &operator-=(NM const &y) { return this->operator=(operator-(y)); }
    NM &operator*=(NM const &y) { return this->operator=(operator*(y)); }
    NM  operator+(NM const &y) const { return (v() + y.v()) % M; }
    NM  operator+(T const &y) const { return this->operator+(NM(y)); }
    NM  operator-(NM const &y) const { return (v() - y.v()) % M; }
    NM  operator-(T const &y) const { return this->operator-(NM(y)); }
    NM  operator*(NM const &y) const { return (v() * y.v()) % M; }
    NM  operator*(T const &y) const { return this->operator*(NM(y)); }
    NM  operator/(NM const &y) const { return this->operator*(inverse(y)); }
};

ll const  MOD  = 1e9 + 7;
int const NMAX = 1e7;
using NM       = NumMod<MOD, ll>;

NM fact[NMAX], inv[NMAX], inv_fact[NMAX];

void precompute_fact(void)
{
    inv[1] = fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < NMAX; ++i)
    {
        if (i > 1)
            inv[i] = MOD - ll(inv[MOD % i] * (MOD / i));
        fact[i]     = fact[i - 1] * i;
        inv_fact[i] = inv_fact[i - 1] * inv[i];
    }
}

template <typename T>
T binpow(T a, ll b)
{
    T ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

NM inverse(NM const &y) { return binpow(y, y.MOD - 2); }

ll C(int n, int k)
{
    if (k > n)
        return 1;
    // return fact[n] * inv_fact[k] * inv_fact[n - k]; // If precomputed in O(1)
    return ll(fact[n] / (fact[n - k] * fact[k]));
}

int mult(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
int add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
