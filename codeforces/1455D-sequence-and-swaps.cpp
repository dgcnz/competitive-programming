/** @file
 * @date                2021-01-07
 * @url                 https://codeforces.com/contest/1455/problem/D
 * @tags                greedy, segment_tree, data_structures
 * @status              AC
 * @score               5
 * @difficulty          4
 * @editorial           no
 * @reading_time        1
 * @thinking_time       25
 * @coding_time         20
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 *
 * Some key observations are:
 * 1. $x$ always increases.
 * 2. Because of 1., after performing a swap on $a_i$, we will only be able
 * to swap $a_j$, such that $a_j > a_i$.
 * 3. Because of 2. (and the fact that we want to sort $A$), after performing a
 * swap on $a_i$, we will only be able to swap $a_j$, such that $j > i$.
 *
 * Observation 2 and 3 suggests a greedy approach.
 *
 * For a position $i$, assume the range $1,...i - 1$ is sorted. Let's split into
 * cases:
 *
 * - If $i...n$ is sorted, we finish.
 * - Otherwise, we have two cases::
 *    - If $x < a_i$, we know that we have to swap, because otherwise we would
 * leave `a[i....n]` unsorted.
 *    - Otherwise, we can't do anything.
 * - After considering these cases, it will only be possible to fix
 *   `a[i + 1...n]` iff no element in `a[i + 1, n]` is less than $a_i$.
 *
 * [Editorial](https://codeforces.com/blog/entry/85186) has other nice
 * solutions like a $O(n^2)$ dp or a $O(n)$ greedy (which is quite similar to
 * mine).
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int op(int a, int b) { return min(a, b); }
int e() { return 0x7fffffff; }

int solve(vi a, int x)
{
    using RMQ = atcoder::segtree<int, op, e>;

    int          n = isz(a);
    vector<bool> sorted_suffix(n, false);

    int last = a[n - 1];
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] <= last)
            sorted_suffix[i] = true;
        else
            break;
        last = a[i];
    }

    RMQ rmq(a);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (sorted_suffix[i])
            break;
        else
        {
            if (x < a[i])
            {
                swap(a[i], x);
                ans++;
            }
            if (rmq.prod(i + 1, n) < a[i])
                return -1;
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vi a(n);
        for (auto &ai : a)
            cin >> ai;

        cout << solve(a, x) << endl;
    }
    return 0;
}
