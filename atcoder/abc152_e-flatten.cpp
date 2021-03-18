/** @file
 * @date                2021-03-15
 * @url                 https://atcoder.jp/contests/abc152/tasks/abc152_e
 * @tags                number_theory, sieve, math
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         30
 * @time_complexity     O(n \sqrt(n))
 * @memory_complexity   O(n)
 * @idea
 * Same idea as [Editorial](https://img.atcoder.jp/abc152/editorial.pdf).
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/math/sieve>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using vi   = vector<int>;
using ll   = long long;
using mint = modint1000000007;

int const   NMAX = 1e6 + 11;
Sieve<NMAX> sieve;

map<int, int> count_factors(int x)
{
    map<int, int> ans;
    for (ll p : sieve.primes)
    {
        if (p * p > x)
            break;
        while (x % p == 0)
            ans[p]++, x /= p;
    }
    if (x > 1)
        ans[x]++;
    return ans;
}

int solve(vi a)
{
    int                   n = a.size();
    map<int, int>         cnt;
    vector<map<int, int>> factor_cnt(n);
    // O(n sqrt(n))
    for (int i = 0; i < n; ++i)
    {
        // O(sqrt(a[i]))
        factor_cnt[i] = count_factors(a[i]);

        // O(sqrt(a[i]))
        for (auto [f, c] : factor_cnt[i])
            cnt[f] = max(cnt[f], c);
    }

    mint y = 1;
    // O(n log c)
    for (auto [f, c] : cnt)  // O(n)
        y *= mint(f).pow(c); // O(log c)

    auto accumulator = [y](mint acc, int ai) { return acc + y / mint(ai); };
    return accumulate(all(a), mint(0), accumulator).val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi a(n);
    for (auto &ai : a)
        cin >> ai;

    cout << solve(a) << endl;
    return 0;
}
