/** @file
 * @date                2020-12-15
 * @url                 https://codeforces.com/contest/1462/problem/F
 * @tags                sorting, brute_force
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        2
 * @thinking_time       15
 * @coding_time         10
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * For each range $(l, r)$ present in the array, see how many ranges wouldn't be
 * covered and keep the one that yields the minimum answer.
 *
 * To compute $ans_{l, r}$, note that we only need to know $ans_l$ and $ans_r$:
 *
 * $$ans_l = \text{#right endings that are less than } l $$
 *
 * $$ans_r = \text{#left endings that are greater than } r $$
 *
 * We can solve those queries in $O(\log{n})$ each with two arrays:
 * 1. $sorted_l$: Array sorted by left borders.
 * 2. $sorted_r$: Array sorted by right borders.
 *
 * For example, for a given range $l, r$ to compute $ans_l$ we only need to
 * binary search (on $sorted_r$) the first range whose $r$ is less than $l$. The
 * answer is the number of elements that precede it. Pretty much the same thing
 * for $ans_r$.
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

int solve(vector<ii> &a)
{
    int n = isz(a);
    vi  lb(n), rb(n);

    for (int i = 0; i < n; ++i)
        lb[i] = a[i].first, rb[i] = a[i].second;

    sort(all(lb)), sort(all(rb));

    int ans = 1e9 + 7;
    for (auto [l, r] : a)
    {
        int ansl = distance(begin(rb), lower_bound(all(rb), l)),
            ansr = distance(upper_bound(all(lb), r), end(lb));
        ans      = min(ans, ansl + ansr);
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
        cin >> n;

        vector<ii> a(n);
        for (auto &[l, r] : a)
            cin >> l >> r;

        cout << solve(a) << endl;
    }
    return 0;
}
