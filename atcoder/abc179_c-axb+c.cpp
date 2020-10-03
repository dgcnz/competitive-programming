#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using vi  = vector<int>;
using mii = map<int, int>;

const int NMAX = 1e7 + 11; // okay for range <= INT_MAX

bitset<NMAX> is_prime; // is_prime[i], true if number i is prime, else false
vector<int>  primes;   // primes[i], prime at pos i

mii prime_factors(ll n)
{
    mii factors;
    ll  i = 0, pf = primes[i];

    while (pf * pf <= n)
    {
        while (n % pf == 0)
        {
            ++factors[pf];
            n = n / pf;
        }
        pf = primes[++i];
    }

    if (n != 1) // If n is prime then it will stay the same, add n.
        ++factors[n];
    return factors;
}

void sieve(ll sieve_size) // fi primes until upperbound inclusive
{
    is_prime.set(); // set all bits to true
    is_prime[0] = is_prime[1] = 0;

    for (ll i = 2; i <= sieve_size; i++)
        if (is_prime[i])
        {
            for (ll j = i * i; j <= sieve_size; j += i)
                is_prime[j] = 0;
            primes.push_back((int)i);
        }
}

int main(void)
{
    int n;
    cin >> n;

    sieve(NMAX);

    ll ans = 0;
    for (int x = 1; x < n; ++x)
    {
        ll   cur     = 1;
        auto factors = prime_factors(x);
        for (auto [k, v] : factors)
            cur *= v + 1;
        ans += cur;
    }

    cout << ans << endl;
    return 0;
}
