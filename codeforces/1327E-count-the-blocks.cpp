/** @file
 *
 * @title               Count The Blocks
 * @url                 https://codeforces.com/contest/1327/problem/E
 * @tags                math, combinatorics
 *
 * @status              AC
 * @score               3
 * @difficulty          4
 * @editorial           yes
 *
 * @reading_time        3
 * @thinking_time       50
 * @coding_time         5
 * @debug_time          10
 *
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 *      General idea:
 *      - For a block of size i, you have 10 ways to choose it.
 *      - The two neighboring digits have 9 ways each to be chosen.
 *      - The remaining digits have 10^{n - i - 2} ways to be chosen.
 *
 *      Implementation details:
 *      - Precompute powers of 10 mod 998244353.
 *      - To ease computation, distinguish between border and inner blocks.
 *      - See editorial for info on last point.
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

int const MOD  = 998244353;
int const NMAX = 2e5 + 11;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> pten(n, 1);
    for (int i = 1; i < n; ++i)
        pten[i] = (pten[i - 1] * 10) % MOD;

    for (int i = 1; i < n; ++i)
    {
        ll res = 2 * 10 * 9 * pten[n - i - 1];
        res %= MOD;
        res += (n - 1 - i) * 10 * 9 * 9 * pten[max(n - i - 2, 0)];
        res %= MOD;
        cout << res << ' ';
    }
    cout << 10 << endl;
    return 0;
}
