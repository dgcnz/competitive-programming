/** @file
 * @date                2021-01-05
 * @url                 https://codeforces.com/contest/1471/problem/D
 * @tags                number_theory, math
 * @status              AC
 * @score               2
 * @difficulty          4
 * @editorial           no
 * @reading_time        2
 * @thinking_time       60
 * @coding_time         30
 * @time_complexity     O(n \log{a_max})
 * @memory_complexity   O(n)
 * @idea
 * We can do some algebra using the fact that `ab = lcm(a, b) *  gcd(a, b)` to
 * arrive at the conclusion that $a$ and $b$ are adjacent iff $ab$ is a perfect
 * power.
 *
 * This suggests to match elements $a_i$ and $a_j$ such that multiplying their
 * prime decompositions results in a prime decomposition of even exponents
 * (=perfect power). Note that for a given prime decomposition of number $a_i$,
 * we only care about the factors that needs to be matched. Therefore, we can
 * discard the even exponents of each factor. We will end up with a number
 * $a_i' \leq  a_i$ that is the multiplication of the factors that need to be
 * matched.
 *
 * Count the occurrences of each $a_i'$ in a map, call it `cnt`. Note that
 * `cnt[ai']` denotes the number of elements that are adjacent to each other by
 * matching the primes denoted by the number `ai'`.
 *
 * If $w=0$ we only need to take the maximum over all entries of `cnt`.
 *
 * Otherwise, note that if `cnt[ai']` is even, all such elements will be
 * replaced by a perfectly matched number (so they will become  `ai'= 1`), and
 * if it is odd, then all such numbers will keep needing to me matched.
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <int SIZE>
struct Sieve
{
    static_assert(0 <= SIZE and SIZE <= 1e8, "0 <= SIZE <= 1e8");
    using byte = unsigned char;
    std::bitset<SIZE> is_prime;
    std::vector<int>  primes;

    Sieve()
    {
        is_prime.set();
        is_prime[0] = is_prime[1] = 0;
        for (int i = 4; i < SIZE; i += 2)
            is_prime[i] = 0;
        for (int i = 3; i * i < SIZE; i += 2)
            if (is_prime[i])
                for (int j = i * i; j < SIZE; j += i * 2)
                    is_prime[j] = 0;

        for (int i = 2; i < SIZE; ++i)
            if (is_prime[i])
                primes.push_back(i);
    }
};

int const   AMAX = 1e4;
Sieve<AMAX> sieve;

int matchable_factors(int x)
{
    int ans = 1;
    for (ll p : sieve.primes)
    {
        if (p * p > x)
            break;
        while (x % (p * p) == 0)
            x /= (p * p);
        if (x % p == 0)
            ans *= p, x /= p;
    }
    if (x > 1)
        ans *= x;
    return ans;
}

ii solve(vi a)
{
    map<int, int> cnt;

    for (auto ai : a)
        cnt[matchable_factors(ai)]++;

    int maxres[2] = {0, 0}, totalres[2] = {0, 0};
    for (auto [x, c] : cnt)
    {
        if (x == 1)
            continue;
        bool parity    = c & 1;
        maxres[parity] = max(maxres[parity], c);
        totalres[parity] += c;
    }

    return {max({cnt[1], maxres[0], maxres[1]}),
            max(cnt[1] + totalres[0], maxres[1])};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vi a(n);
        for (auto &ai : a)
            cin >> ai;

        auto [w0, wotherwise] = solve(a);

        int q;
        cin >> q;
        while (q--)
        {
            ll w;
            cin >> w;
            if (w == 0)
                cout << w0 << endl;
            else
                cout << wotherwise << endl;
        }
    }
    return 0;
}
