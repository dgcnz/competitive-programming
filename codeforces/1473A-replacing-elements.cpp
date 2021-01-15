/** @file
 * @date                2021-01-14
 * @url                 https://codeforces.com/contest/1473/problem/A
 * @tags                greedy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        0
 * @thinking_time       1
 * @coding_time         2
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * If all elements are less than $d$, then no change is need to be made. Assume
 * otherwise.
 *
 * Note that the optimal strategy is to pick the two smallest values as $a_j$
 * and $a_k$ and replace every $a_i > a_j + a_k$ with their sum. Iff $a_j + a_k
 * \leq d$ then it is possible.
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

bool solve(vi a, int d)
{
    sort(all(a));
    if (a.back() <= d)
        return true;
    if (a.size() > 1 and a[0] + a[1] <= d)
        return true;
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vi a(n);
        for (auto &ai : a)
            cin >> ai;

        cout << (solve(a, d) ? "YES" : "NO") << endl;
    }
    return 0;
}
