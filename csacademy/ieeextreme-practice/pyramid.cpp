#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

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

    friend ostream &operator<<(ostream &os, NM const &y) { return os << y.v(); }
};

ll const  MOD    = 1e9 + 7;
int const SMAX   = 1e5 + 11;
int const LOGMAX = 20;

using NM = NumMod<MOD, ll>;
NM dp[LOGMAX][SMAX];
ll C[2][LOGMAX];

ll solve(int s)
{
    int L = log2(s) + 1, last = 1, cur = 0;
    NM  ans(1);

    C[last][0] = 1;
    for (int n = 2; n <= L; ++n)
    {
        C[cur][0] = 1;
        ll sp     = s - C[cur][0]; // force to take 1 of every element

        for (int i = 1; i <= L; ++i)
        {
            C[cur][i] = (n < i ? 0 : C[last][i - 1] + C[last][i]);
            sp -= C[cur][i];
        }

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int c = 0; c <= sp; ++c)
            {
                auto &ans = dp[i][c];
                ans       = dp[i - 1][c];
                if (c - C[cur][i - 1] >= 0)
                    ans += dp[i][c - C[cur][i - 1]];
            }
        }
        ans += dp[n][sp];
        swap(cur, last);
    }
    return ll(ans);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
