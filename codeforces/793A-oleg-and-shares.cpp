/** @file
 * @date                2020-12-31
 * @url                 https://codeforces.com/problemset/problem/793/A
 * @tags                math, implementation
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Let's say that after some number of operations, all numbers become $x$. Note
 * that $x$ has to be $\min(a_1, a_2,... a_n)$, because it would be suboptimal
 * otherwise.
 *
 * So, if all numbers can reach $x$ by decrementing by $k$, then it should be
 * possible.
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

ll solve(vi a, int k)
{
    int mv  = *min_element(all(a));
    ll  ans = 0;
    for (auto x : a)
    {
        if ((x - mv) % k)
            return -1;
        ans += (x - mv) / k;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    vi a(n);
    for (auto &x : a)
        cin >> x;

    cout << solve(a, k) << endl;
    return 0;
}
