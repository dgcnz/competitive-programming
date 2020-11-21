/** @file
 *
 * @url                 https://codeforces.com/gym/101498/problem/D
 * @tags                math, combinatorics
 *
 * @status              AC
 * @score               4
 * @difficulty          4
 * @editorial           no
 *
 * @reading_time        3
 * @thinking_time       30
 * @coding_time         5
 * @debug_time          5
 *
 * @time_complexity     [O(f(n)))
 * @memory_complexity   [O(f(n))]
 * @idea
 *  - A path in a binary tree can be described by a sequence of l's and r's.
 *  - We need to count such $a$-sized sequences such that they change $b$ times.
 *  - Without loss of generality, such string is of the form: $LRLRLR...LR$,
 * where $L$ and $R$ are blocks of 'l's and 'r's respectively, with a total of
 * $b+1$ blocks and sum of block sizes equal to $a$.
 *  - This probem can be thought as finding all the solutions to the equation:
 *  $$x_1 + x_2 + ... + x_{b + 1} = a$$
 *  - Where $x_i >= 1$.
 *  - This is the stars and bars problem, to which a direct formula is known.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

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
int const NMAX = 1e5 + 11;
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
    // return ll(fact[n] / (fact[n - k] * fact[k]));
    return ll(fact[n] * inv_fact[n - k] * inv_fact[k]);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    precompute_fact();
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << (2 * C(a - 1, b)) % MOD << endl;
    }
    return 0;
}
