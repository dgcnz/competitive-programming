---
layout: post
title: 1082 Sum Of Divisors
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
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
    T x;
  public:
    NumMod<M, T>(T x) : x(x) {}
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
    NumMod<M, T> operator+(NumMod<M, T> const &y) { return (v() + y.v()) % M; }
    NumMod<M, T> operator+(T const &y)
    {
        return this->operator+(NumMod<M, T>(y));
    }
    NumMod<M, T> operator-(NumMod<M, T> const &y) { return (v() - y.v()) % M; }
    NumMod<M, T> operator-(T const &y)
    {
        return this->operator-(NumMod<M, T>(y));
    }
    NumMod<M, T> &operator+=(const NumMod<M, T> &y)
    {
        return this->operator=(operator+(y));
    }
    NumMod<M, T> operator*(NumMod<M, T> y) { return (v() * y.v()) % M; }
    NumMod<M, T> operator*(T y) { return this->operator*(NumMod<M, T>(y)); }
};
ll const MOD = 1e9 + 7;
NumMod<MOD> sum(NumMod<MOD> n) { return n * (n + 1) * ((MOD + 1) / 2); }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;
    NumMod<MOD> ans(0);
    for (ll i = 1; i <= n; ++i)
    {
        ll times = n / i, r = n / times;
        ans += NumMod<MOD>(times) * (sum(r) - sum(i - 1));
        i = r;
    }
    cout << ll(ans) << endl;
    return 0;
}

```
