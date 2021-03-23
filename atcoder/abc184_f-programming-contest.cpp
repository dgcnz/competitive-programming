/** @file
 * @date                2021-03-19
 * @url                 https://atcoder.jp/contests/abc184/tasks/abc184_f
 * @tags                meet_in_the_middle, brute_force, bitmasks
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         20
 * @time_complexity     O((n + \log{n})2^{\frac{n}{2}})
 * @memory_complexity   O(2^{\frac{n}{2}})
 * @idea
 * It's pretty clear that a $O(2^n)$ solution is possible, but can we do better?
 *
 * First of all, it is oddly suspicious that $n$ is small enough to be solvable
 * if we were to halve it. Let's explore that idea a bit further.
 *
 * We could iterate all subsets of the first half of items in
 * $2^{\frac{n}{2}}$ and store all the unique subset sums in $n$ times that.
 * Let's do the same to the second half. We would end up with two sets of sums,
 * and instead of finding the subset sum of all elements we would need to find
 * the biggest sum (less than $t$) from an element from each set. That seems
 * feasible.
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

int solve(ll t, vector<ll> a)
{
    int n = a.size();
    sort(all(a));

    set<ll> lower_half, upper_half;
    for (int mask = 0; mask < (1 << n / 2); ++mask)
    {
        ll x = 0;
        for (int i = 0; i < n / 2; ++i)
            x += a[i] * ((mask >> i) & 1);
        if (x <= t)
            lower_half.insert(x);
    }

    for (int mask = 0; mask < (1 << (n - n / 2)); ++mask)
    {
        ll x = 0;
        for (int i = n / 2; i < n; ++i)
            x += a[i] * ((mask >> (i - n / 2)) & 1);
        if (x <= t)
            upper_half.insert(x);
    }

    ll ans = 0;
    for (auto x : lower_half)
        if (auto it = upper_half.upper_bound(t - x); it != upper_half.begin())
            ans = max(ans, *prev(it) + x);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll  t;
    cin >> n >> t;
    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << solve(t, a) << endl;
    return 0;
}
