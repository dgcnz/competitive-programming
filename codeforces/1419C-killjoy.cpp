/** @file
 * @date                2021-01-10
 * @url                 https://codeforces.com/contest/1419/problem/C
 * @tags                observation, implementation, greedy
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/82817) is pretty nice.
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

int solve(vi a, int x)
{
    if (all_of(all(a), [x](int ai) { return ai == x; }))
        return 0;
    if (accumulate(all(a), 0LL) - isz(a) * x == 0 or find(all(a), x) != a.end())
        return 1;
    return 2;
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
