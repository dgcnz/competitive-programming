/** @file
 * @date                2020-12-28
 * @url                 https://codeforces.com/contest/1469/problem/B
 * @tags                greedy
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        3
 * @thinking_time       20
 * @coding_time         4
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * $f(a)$ is maximized when $a$ is of the form:
 *
 * ```
 * a = r[0, i] . b[0, j] . r[i + 1, n] . b[j + 1, m]
 * ```
 *
 * Where `.` means concatenation and $i$ and $j$ are the indices that maximize
 * their respective prefix sums.
 *
 * The reason behind is that the sum of `a[0... i + j] = r[0, i] .  b[0, j]`
 * will be a consequently the maximal term of $f(a)$ for all $a$.
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

int solve(vi r, vi b)
{
    int n = isz(r), m = isz(b);
    vi  pr(n, 0), pb(m, 0);
    partial_sum(all(r), begin(pr));
    partial_sum(all(b), begin(pb));
    return max(*max_element(all(pr)), 0) + max(*max_element(all(pb)), 0);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;

        vi r(n);
        for (auto &x : r)
            cin >> x;

        cin >> m;
        vi b(m);
        for (auto &x : b)
            cin >> x;

        cout << solve(r, b) << endl;
    }
    return 0;
}
