/** @file
 * @date                2020-11-26
 * @url                 https://url.com
 * @tags                number_theory, primes
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         2
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n \log{n})
 * @idea
 * Let $n = 10001$.
 * By the asymptotic law of distribution of prime numbers
 * [ref](https://en.wikipedia.org/wiki/Prime_number_theorem):
 *
 * $$ p_n \sim n \log{n} $$
 *
 * This tells us that we can sieve up to a bit more than $ 10001 \log{10001}$ to
 * get the answer.
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

const int PMAX = 1e7 + 11;

bitset<PMAX> is_prime;
vector<int>  primes;

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
    sieve();
    cout << primes[10000] << endl; // 0-indexed
    return 0;
}
