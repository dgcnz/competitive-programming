---
layout: post
mathjax: true
title: 1746 Array Description
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
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}
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
};
ll const MOD = 1e9 + 7;
using NM = NumMod<MOD, ll>;
ll solve(int n, int m, vi a)
{
    vector<vector<NM>> dp(n + 1, vector<NM>(m + 2, 0));
    if (a[1] == 0)
        for (int x = 1; x <= m; ++x)
            dp[1][x] = 1;
    else
        dp[1][a[1]] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == 0)
            for (int x = 1; x <= m; ++x)
                dp[i][x] = dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1];
        else
        {
            dp[i][a[i]] =
                dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1];
        }
    }
    return ll(accumulate(dp[n].begin(), dp[n].end(), NM(0)));
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi a(n + 1, 0);
    read_n(next(a.begin()), n);
    cout << solve(n, m, a) << endl;
    return 0;
}

{% endraw %}
```
