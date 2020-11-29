/** @file
 * @date                2020-11-26
 * @url                 https://projecteuler.net/problem=3
 * @tags                sieve, factorization
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       4
 * @coding_time         4
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(\sqrt{n})
 * @idea
 * - Sieve until root of n and factorize.
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

ll const n         = 600851475143;
int constexpr NMAX = 1e7;

bitset<NMAX> is_prime;
vector<int>  primes;

vi prime_factors(ll n)
{
    vi factors;
    ll i = 0, pf = primes[i];

    while (pf * pf <= n)
    {
        while (n % pf == 0)
        {
            factors.push_back(pf);
            n = n / pf;
        }
        pf = primes[++i];
    }

    if (n != 1)
        factors.push_back(n);
    return factors;
}

void sieve(void)
{
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    for (ll i = 2; i < NMAX; i++)
        if (is_prime[i])
        {
            for (ll j = i * i; j < NMAX; j += i)
                is_prime[j] = 0;
            primes.push_back(i);
        }
}

int main(void)
{
    sieve();
    auto factors = prime_factors(n);
    cout << factors.back() << endl;
    return 0;
}
