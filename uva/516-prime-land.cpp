/** @file
 * @date                2020-11-26
 * @url
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=457
 * @tags                number_theory, factorization
 * @status              AC
 * @score               0
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         20
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * - Reconstruct number.
 * - Prime factorize number - 1.
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

const int PMAX = 1e5 + 11;

bitset<PMAX> is_prime;
vector<int>  primes;

int binpow(int base, int exp)
{
    int ans = 1;
    while (exp > 0)
    {
        if (exp & 1)
            ans *= base;
        base *= base;
        exp >>= 1;
    }
    return ans;
}

map<int, int> prime_factors(ll n)
{
    map<int, int> factors;
    ll            i = 0, pf = primes[i];
    while (pf * pf <= n)
    {
        while (n % pf == 0)
        {
            factors[pf]++;
            n = n / pf;
        }
        pf = primes[++i];
    }
    if (n != 1)
        factors[n]++;
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
    string line;
    sieve();
    while (getline(cin, line) and line[0] != '0')
    {
        stringstream ss(line);
        int          n = 1, p, e;
        while (ss >> p >> e)
            n *= binpow(p, e);

        auto factors = prime_factors(n - 1);

        for (auto it = factors.rbegin(); it != factors.rend(); ++it)
        {
            cout << it->first << " " << it->second;
            if (next(it) != factors.rend())
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
