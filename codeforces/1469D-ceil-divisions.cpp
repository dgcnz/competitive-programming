/** @file
 * @date                2021-01-05
 * @url                 https://codeforces.com/contest/1469/problem/D
 * @tags                constructive, math
 * @status              AC
 * @score               1
 * @difficulty          3
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/86082).
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

inline int ceil(int a, int b) { return (a + b - 1) / b; }

int bs(int l, int r, function<bool(int)> p)
{
    // 0 0 0 0 1 1
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

void solve(int n, vector<ii> &ans)
{
    if (n == 2)
        return;
    int i = bs(1, n - 1, [n](int x) { return x >= ceil(n, x); });

    for (int j = i + 1; j < n; ++j)
        ans.emplace_back(j, n);
    ans.emplace_back(n, i);
    ans.emplace_back(n, i);
    solve(i, ans);
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
        vector<ii> ans;
        solve(n, ans);

        cout << ans.size() << endl;
        for (auto [x, y] : ans)
            cout << x << " " << y << endl;
        cout << endl;
    }
    return 0;
}
