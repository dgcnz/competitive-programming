/** @file
 * @date                2020-12-11
 * @url                 https://atcoder.jp/contests/abc145/tasks/abc145_d
 * @tags                counting, math
 * @status              AC
 * @score               1
 * @difficulty          3
 * @editorial           yes
 * @reading_time        2
 * @thinking_time       60
 * @coding_time         10
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * This [blog](https://shunsuke.me/competitive/atcoder/abc145_d/) helped me
 * understand the [Editorial](https://img.atcoder.jp/abc145/editorial.pdf).
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
int const NMAX = 1e6 + 11;
using NM       = NumMod<MOD, ll>;
NM   fact[NMAX], inv[NMAX], inv_fact[NMAX];
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
    if (k > n or k < 0)
        return 0;
    return ll(fact[n] * inv_fact[n - k] * inv_fact[k]);
}

int solve(int x, int y)
{
    if ((x + y) % 3 != 0)
        return 0;

    precompute_fact();

    int n = (2 * x - y) / 3, m = (2 * y - x) / 3;
    return C(n + m, n);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    cin >> x >> y;
    cout << solve(x, y) << endl;
    return 0;
}
