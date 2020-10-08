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

// IDEA:
// Given a fixed-sized triangle of width n, we know that we can uniquely
// determine the value at (1, 1) by the bottom row, call it A (0-indexed).
//
// The formula is: sum {C(n - 1, i) * A[i] | i <- [0, i - 1]}           (1)
//
// Note that n can be at most log2(s) + 1 of size.
//
// However, it seems unclear how to handle this, since different sizes of
// triangles will yield different values of the binomial coefficients.
//
// -----------------------------------------------------------------------------
// To simplify our reasoning, how would we solve this problem if we could only
// work with triangles of a fixed size k?
//
// This seems like an unbounded knapsack problem where each item at position i,
// has a value of C(n - 1, i). (If this is not clear, think what our formula (1)
// says. Think of C(n - 1, i) as the value of item i and A[i] as the number of
// times we take that value.)
//
// dp(i, sum) : #ways to reach sum if we use the first i elements
// dp(i, sum) = dp(i - 1, sum) + dp(i, sum - C(n - 1, i))
//
// However, we notice that the problem requires us to pick strictly positive
// numbers, meaning >= 1. Our DP formulation assumes that we may take an item 0
// times, which is equal to saying that a[i] might be 0.
//
// To our luck, there's an easy fix for this. For a target sum S, let's define
// a new S' such that:
//
//      S' = S - {C(n - 1, i) | i <- [0, n - 1]}
//
// Now, the answer for this case would be dp(n, S'), since S' implies that we
// have already taken 1 time each item.
//
// dp(n, S') would be number of ways to choose a the numbers of the bottom row
// given a fixed size of k such that they result on the square at (1, 1) being
// S.
//
// The dp state space would be O(log(s) * s) and each transition would be
// performed on O(1), so our final complexity would be O(slog(s)).
//
// -----------------------------------------------------------------------------
//
// Now that we have efficiently solved this simpler problem, it's
// straightforward to notice that the final answer to the original problem is
// just to sum all the answers of these smaller independent subproblems.
//
// As we noted earlier, the biggest triangle that could contribute to the final
// answer is of size log2(s) + 1, so we will just execute our dp algorithm that
// amount of times, yielding an overall complexity of O(slog^2(s)).
//
// Some implementation details:
// The binomial coefficient formula is: C(n, m)  = C(n - 1, m - 1) + C(n - 1, m)
// At each triangle of size k, we only need {C(k - 1, i) | i <- [0, k - 1]}, so
// we can reuse the previously computed coefficients to compute all the current
// ones in O(log(s)) (Remember, log(s) is the maximum size of the triangle).

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
        ll sp     = s - C[cur][0];

        for (int i = 1; i <= L; ++i)
        {
            C[cur][i] = (n < i ? 0 : C[last][i - 1] + C[last][i]);
            sp -= C[cur][i]; // force to take 1 of every element
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
