/** @file
 * @date                2021-01-12
 * @url                 https://codeforces.com/contest/1368/problem/D
 * @tags                greedy, bitmasks, math
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         8
 * @time_complexity     O(n \log{a_{max}})
 * @memory_complexity   O(n)
 * @idea
 * To maximize each term of the summation, we should try to make large numbers
 * as large as possible (to maximize the contribution of each $a_i^2$).
 *
 * Note that each operation effectively transfers all $1$'s from a number $a_i$
 * to another number $a_j$ (in binary).
 *
 * We can think of a greedy strategy where we redistribute the $1$'s and
 * concentrate them in a few numbers in order to make them larger.
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

ll solve(vi a)
{
    int const BSZ = 20;
    vi        cnt(BSZ, 0);
    for (auto ai : a)
        for (int i = 0; i < BSZ; ++i)
            cnt[i] += (ai >> i) & 1;

    vector<ll> ans(a.size(), 0);
    for (auto &ai : ans)
    {
        for (int i = 0; i < BSZ; ++i)
        {
            if (cnt[i])
            {
                ai |= (1 << i);
                cnt[i]--;
            }
        }
    }

    transform(all(ans), begin(ans), [](ll x) { return x * x; });
    return accumulate(all(ans), 0LL);
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
