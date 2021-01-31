/** @file
 * @date                2021-01-30
 * @url                 https://atcoder.jp/contests/abc190/tasks/abc190_f
 * @tags                constructive, inversions, fenwick_tree, dp
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       25
 * @coding_time         10
 * @time_complexity     O(n \log{n} + n)
 * @memory_complexity   O(a_{max} + n)
 * @idea
 * Let's denote $a_i$ to the $i$th element in the original array (0-indexed).
 *
 * Think about how does the inversion count for a given shift $k - 1$ to $k$.
 *
 * 1. The element $a_{k - 1}$ will become the last element. All other elements
 * will be at its left, so that means that it will gain an inversion count of
 * the quantity of such elements greater than it.
 * 2. All other elements in step $k - 1$ where at the right of such element, so
 * they will lose all inversions they had with $a_{k - 1}$.
 *
 * This leads us to formulate the following dp:
 *
 * $dp(k) = dp(k - 1) + |{a_j > a_{k - 1}}| - |{a_j < a_{k - 1}}|$
 *
 * Since $a$ is a permutation of $0... n - 1$:
 * 1. $|{a_j > a_{k - 1}}| = n - 1 - a_{k - 1}$
 * 2. $|{a_j < a_{k - 1}}| = a_{k - 1}$
 *
 * Which would result into:
 * $dp(k) = dp(k - 1) + n - 1 - 2 a_{k - 1}$
 *
 * Finally, we can compute $dp(0)$ in $O(n \log{n})$ using the standard fenwick
 * tree approach to count inversions.
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll count_inversions(const vector<ll> &a)
{
    ll               amax = *max_element(all(a)) + 1, ans = 0;
    fenwick_tree<ll> fw(amax);
    for (auto ai : a)
    {
        ans += fw.sum(ai + 1, amax);
        fw.add(ai, 1);
    }
    return ans;
}

vector<ll> solve(const vector<ll> &a)
{
    int n = a.size();

    vector<ll> ans(n);

    ans[0] = count_inversions(a);
    for (int k = 1; k < n; ++k)
        ans[k] = ans[k - 1] + n - 1 - 2 * a[k - 1];
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;

    auto ans = solve(a);
    for (auto x : ans)
        cout << x << endl;
    return 0;
}
