/** @file
 * @date                2020-12-30
 * @url                 https://codeforces.com/contest/1466/problem/A
 * @tags                math, brute_force
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         3
 * @time_complexity     O(n^2)
 * @memory_complexity   O(n)
 * @idea
 * In the formula $A = \frac{h_b b}{2}$, the only variable that changes is the
 * base length, $b$. List all pairs, of points on the x axis and count the
 * unique distances.
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
    int n = isz(a), ans = 0;

    vector<bool> vis(100, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int b = abs(a[i] - a[j]);
            if (vis[b])
                continue;
            vis[b] = true;
            ans++;
        }
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
        vi a(n);
        for (auto &x : a)
            cin >> x;
        cout << solve(a) << endl;
    }
    return 0;
}
