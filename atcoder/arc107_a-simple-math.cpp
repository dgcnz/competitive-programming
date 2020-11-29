/** @file
 * @date                2020-11-24
 * @url                 https://atcoder.jp/contests/arc107/tasks/arc107_a
 * @tags                math
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        0
 * @thinking_time       4
 * @coding_time         4
 * @time_complexity     O(log(MOD))
 * @memory_complexity   O(1)
 * @idea
 * We only need to manipulate the summation a bit to represent it in closed
 * forms. For example:
 *
 * $$ \sum_{i = 1}^{C} = \frac{C * (C + 1)}{2} $$
 *
 * Since we'are dealing with modular arithmetic, we'll need to compute the
 * inverse of 2. The final formula is:
 *
 * $$ \frac{A * (A + 1)}{2} \times \frac{B * (B + 1)}{2} \times \frac{C * (C +
 * 1)}{2} $$
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

ll const MOD = 998244353;
using NM     = NumMod<MOD, ll>;

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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;

    NM ans = NM(a * (a + 1)) / 2 * NM(b * (b + 1)) / 2 * NM(c * (c + 1)) / 2;
    cout << ll(ans) << endl;

    return 0;
}
