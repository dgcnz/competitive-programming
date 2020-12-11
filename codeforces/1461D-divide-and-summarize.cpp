/** @file
 * @date                2020-12-11
 * @url                 https://codeforces.com/contest/1461/problem/D
 * @tags                sorting, divide_and_conquer
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        2
 * @thinking_time       10
 * @coding_time         10
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Note that for a given array $A$, you can produce all possible subarray sums
 * by performing splits recursively until it's no longer possible.
 *
 * Also, note that the order of the elements does not matter, because splitting
 * and getting the sum of a subarray are order invariant.
 *
 * Algorithm:
 * 1. Sort array.
 * 2. Precompute prefix sums of sorted array (to be able to do range sums).
 * 3. Perform splitting recursively, and for each [l, r], add its sum to the
 * answer set and find the new middle by binary searching the midpoint.
 * 5. For each query, binary search on the answer set.
 *
 * Note that the recurrence tree has on average at most $O(\log{a_{max}})$
 * height, because the maximum difference between two elements is $10^9$ and
 * that halves on each split. Credits to Senhor
 * [nitor](https://codeforces.com/profile/nitor) for the complexity analysis.
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

int const NMAX = 1e5 + 11;

ll      n, a[NMAX], pa[NMAX];
set<ll> answers;

ll sum(int l, int r) { return pa[r] - (l == 0 ? 0 : pa[l - 1]); }

void solve(int l, int r)
{
    if (r < l or l < 0 or r >= n)
        return;

    int mx = a[r], mn = a[l], md = (mx + mn) / 2;
    int mdix = distance(a, upper_bound(a + l, a + r + 1, md));
    answers.insert(sum(l, r));

    if (mdix - 1 != r)
        solve(l, mdix - 1);
    if (mdix != l)
        solve(mdix, r);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        answers.clear();

        int q;
        cin >> n >> q;
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a, a + n);
        partial_sum(a, a + n, pa);
        solve(0, n - 1);

        while (q--)
        {
            ll s;
            cin >> s;
            cout << (answers.find(s) != end(answers) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
