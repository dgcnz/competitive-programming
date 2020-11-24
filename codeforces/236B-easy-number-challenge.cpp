/** @file
 * @date                2020-11-24
 * @url                 https://codeforces.com/contest/236/problem/B
 * @tags                number_theory, divisors, brute_force
 * @status              AC
 * @score               4
 * @difficulty          3
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         8
 * @time_complexity     O(abc * \log{abc})
 * @memory_complexity   O(abc)
 * @idea
 * - Precompute the divisor function up to $a \times b \times c$.
 * - A way to interpret this is the following: For each possible number, we'll
 * increment the divisor count of all its multiples.
 * - Brute-force the solution.
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

vi precompute_divisors(int n)
{
    vi d(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            d[j]++;

    return d;
}

int solve(int a, int b, int c)
{
    int const MOD = 1 << 30;

    ll   ans = 0;
    auto d   = precompute_divisors(a * b * c);

    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            for (int k = 1; k <= c; ++k)
                ans = (ans + d[i * j * k]) % MOD;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
    return 0;
}
