/** @file
 * @date                2020-11-24
 * @url
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1431
 * @tags                number_theory, primes
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           yes
 * @reading_time        10
 * @thinking_time       2
 * @coding_time         5
 * @time_complexity     O(\sqrt{2^n})
 * @memory_complexity   O(1)
 * @idea
 * - Testing primality up to the square root does the trick.
 *
 * Implementation details:
 * - Make sure you precompute the square root, instead of constantly squaring x.
 * That did all the difference for me (from 3s TLE to 0ms AC).
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

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int x = 2, sq = sqrt(n); x <= sq; ++x)
        if (n % x == 0)
            return false;
    return true;
}

int main(void)
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        if (not is_prime(n))
            printf(
                "Given number is NOT prime! NO perfect number is available.\n");
        else if (is_prime((1LL << n) - 1))
            printf("Perfect: %lld!\n", (1LL << (n - 1)) * ((1LL << n) - 1));
        else
            printf("Given number is prime. But, NO perfect number is "
                   "available.\n");
    }

    return 0;
}
