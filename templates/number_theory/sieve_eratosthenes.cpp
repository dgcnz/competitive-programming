#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using vi  = vector<int>;
using mii = map<int, int>;

const int NMAX = 1e7 + 11;

bitset<NMAX> is_prime; // is_prime[i], true if number i is prime, else false
vector<int>  prime;    // prime[i], prime at pos i

vi prime_factors(ll n)
{
    // mii factors;
    vi factors;
    ll i = 0, pf = prime[i];

    while (pf * pf <= n)
    {
        while (n % pf == 0)
        {
            factors.push_back(pf);
            // ++factors[pf];
            n = n / pf;
        }
        pf = prime[++i];
    }

    if (n != 1) // If n is prime then it will stay the same, add n.
        factors.push_back(n); // ++factors[n];
    return factors;
}

void sieve(ll maxn) // fi primes until maxn inclusive
{
    ll sieve_size = maxn + 1;

    is_prime.set(); // set all bits to true
    is_prime[0] = is_prime[1] = 0;

    for (ll i = 2; i <= sieve_size; i++)
        if (is_prime[i])
        {
            for (ll j = i * i; j <= sieve_size; j += i)
                is_prime[j] = 0;
            prime.push_back((int)i);
        }
}
