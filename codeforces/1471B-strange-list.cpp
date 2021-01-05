/** @file
 * @date                2021-01-05
 * @url                 https://codeforces.com/contest/1471/problem/B
 * @tags                math, implementation
 * @status              AC
 * @score               0
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       8
 * @coding_time         4
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Disclaimer: I actually don't know how to explain this well kskjsdkjs.
 *
 * Let `cnt[i]` be the maximum number of times $x$ divides $a_i$.
 *
 * Let `minix` be the first index such that:
 *
 * $$minix = argmin_i(cnt_{i})$$
 *
 * Note three things:
 * - First, that `cnt[i]` tells us how many times the robot may perform its
 * operation on $a_i$ and the elements $a_i$ produce.
 * - Second, that the elements $a_i$ produce after an operation have a
 * contribution of $a_i$ to the sum.
 * - Third, that the operation will be performed to descendents of elements
 * $a_i$ until $a_{minix}$ is last expanded.
 *
 * So, we'll divide the array into those elements at the left of `minix` and
 * those at the right of it. We'll observe that the elements at the left will be
 * expanded at most `min(cnt[i], cnt[minix] + 1]`  times and those at the right
 * `cnt[minix]` times.
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

ll fit(ll ai, ll x)
{
    ll ans = 0;
    while (ai % x == 0)
    {
        ans++;
        ai /= x;
    }
    return ans;
}

ll solve(vector<ll> a, ll x)
{
    int n = isz(a);

    vector<ll> cnt(n, 0);
    for (int i = 0; i < n; ++i)
        cnt[i] = fit(a[i], x);

    ll  ans   = accumulate(all(a), 0LL);
    int minix = distance(begin(cnt), min_element(all(cnt)));

    for (int i = 0; i < n; ++i)
    {
        if (i < minix)
            cnt[i] = min(cnt[i], cnt[minix] + 1);
        if (i > minix)
            cnt[i] = cnt[minix];
        ans += cnt[i] * a[i];
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
        int n;
        ll  x;
        cin >> n >> x;
        vector<ll> a(n);
        for (auto &ai : a)
            cin >> ai;

        cout << solve(a, x) << endl;
    }
    return 0;
}
