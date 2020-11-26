/** @file
 * @date                2020-11-23
 * @url                 https://atcoder.jp/contests/abc142/tasks/abc142_d
 * @tags                math, sorting
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         15
 * @time_complexity     O(\sqrt{n})
 * @memory_complexity   O(\sqrt{n})
 * @idea
 * First note that all the common divisors of $A$ and $B$ are the factors of
 * $gcd(A, B)$.
 *
 * The key observation is that the optimal answer is the set of all prime
 * factors of $gcd(A, B)$ and 1. It is trivial to see that such a set is indeed
 * mutually coprime.
 *
 * The intuition behind this is that if we were to add a composite factor to our
 * answer set, then it would always be a better choice to add its prime factors.
 *
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
using vi = vector<int>;

vi prime_factors(ll n)
{
    vi factors;
    for (ll i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    ll A, B;
    cin >> A >> B;

    ll   g       = gcd(A, B);
    auto factors = prime_factors(g);
    cout << 1 + distance(begin(factors), unique(all(factors))) << endl;

    return 0;
}
