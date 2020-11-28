/** @file
 * @date                2020-11-27
 * @url                 https://codeforces.com/contest/1342/problem/C
 * @tags                math, lcm
 * @status              AC
 * @score               2
 * @difficulty          5
 * @editorial           yes
 * @reading_time        4
 * @thinking_time       60
 * @coding_time         15
 * @time_complexity     O(ab + q)
 * @memory_complexity   O(ab)
 * @idea
 * - We first observe that the after every $lcm(a, b)$, the pattern of moduli
 * repeats itself.
 * - This suggest the idea of precomputing the result for the first block of
 * numbers ( (of size $lcm(a,b)$). We'll refer to this array as `block` or
 * `pre`.
 * - Querying for a [0, r] range seems reasonably simple: We count how many full
 * blocks fit in our range + the part of the block that was cut by $r$.
 * - We can solve the problem's query [l, r] by splitting it into two of our
 * queries. [0, r] - [0, l - 1].
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

int const AMAX = 200 + 5;

ll period, pre[AMAX * AMAX];

inline ll cnt(ll r) { return pre[period - 1] * (r / period) + pre[r % period]; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, q;
        cin >> a >> b >> q;

        period = lcm(a, b);
        pre[0] = 0;
        for (int x = 1; x <= period; ++x)
            pre[x] = pre[x - 1] + (((x % a) % b) != ((x % b) % a));

        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            cout << cnt(r) - cnt(l - 1) << " ";
        }
        cout << endl;
    }
    return 0;
}
