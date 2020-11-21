---
layout: post
mathjax: true
title: 1713 Counting Divisors
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
int const PMAX = 1e7;
bitset<PMAX> is_prime;
vector<int> primes;
using mii = map<int, int>;
mii prime_factors(ll n)
{
    mii factors;
    ll i = 0, pf = primes[i];
    while (pf * pf <= n)
    {
        while (n % pf == 0)
        {
            ++factors[pf];
            n = n / pf;
        }
        pf = primes[++i];
    }
    if (n != 1)
        ++factors[n];
    return factors;
}
void sieve(void)
{
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i < PMAX; i++)
        if (is_prime[i])
        {
            for (ll j = i * i; j < PMAX; j += i)
                is_prime[j] = 0;
            primes.push_back(i);
        }
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    sieve();
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        auto factors = prime_factors(ai);
        ll ans = accumulate(factors.begin(), factors.end(), 1LL, [](ll acc, ii kv) {
            return acc * (kv.second + 1);
        });
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```
