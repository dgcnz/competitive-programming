/** @file
 * @date                2020-12-29
 * @url                 https://codeforces.com/problemset/problem/279/B
 * @tags                two_pointers, brute_force
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * We need to find a pair of indices `[l, r]` such that the sum of the book
 * times  in this interval is less than $t$ and is maximal.
 *
 * We may fix the left border, $l$, and use binary search or a two pointers
 * approach to find $r$.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vi a, int t)
{
    int n = isz(a), r = 0, ans = 0;

    vi pa(n);
    partial_sum(all(a), begin(pa));
    auto sum = [pa](int l, int r) { return pa[r] - (l == 0 ? 0 : pa[l - 1]); };

    for (int l = 0; l < n; ++l)
    {
        // yes yes yes no no
        // r first no
        while (r < n and sum(l, r) <= t)
            ++r;
        ans = max(ans, r - l);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, t;
    cin >> n >> t;

    vi a(n);
    for (auto &x : a)
        cin >> x;

    cout << solve(a, t) << endl;

    return 0;
}
