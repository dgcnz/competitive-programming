/** @file
 * @date                2020-12-30
 * @url                 https://codeforces.com/contest/1466/problem/B
 * @tags                greedy
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * From start to end, increase element if it has already been encountered before
 * (remember elements are given in non-decreasing order). Then, count unique elements.
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

int solve(vi a)
{
    int n = isz(a);

    vector<bool> vis(a.back() + 5, false);
    for (int i = 0; i < n; ++i)
    {
        if (vis[a[i]])
            a[i]++;
        vis[a[i]] = true;
    }
    return distance(begin(a), unique(all(a)));
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
        vi a(n);
        for (auto &x : a)
            cin >> x;
        cout << solve(a) << endl;
    }
    return 0;
}
