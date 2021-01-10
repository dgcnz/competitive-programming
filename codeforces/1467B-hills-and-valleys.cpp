/** @file
 * @date                2021-01-08
 * @url                 https://codeforces.com/contest/1467/problem/B
 * @tags                brute_force, implementation
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       8
 * @coding_time         15
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Try all positions and keep the one that reduces hills/valleys the most.
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
    int  n       = isz(a);
    auto is_hill = [n, &a](int i) {
        return (i <= 0 or i >= n - 1) ? false
                                      : a[i - 1] < a[i] and a[i] > a[i + 1];
    };

    auto is_valley = [n, &a](int i) {
        return (i <= 0 or i >= n - 1) ? false
                                      : a[i - 1] > a[i] and a[i] < a[i + 1];
    };

    auto is = [is_hill, is_valley](int i) {
        return is_hill(i) or is_valley(i);
    };

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += is(i);

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int  temp = a[i], cur = 0;
        bool l = is(i - 1), m = is(i), r = is(i + 1);
        if (i > 0)
        {
            a[i] = a[i - 1];
            cur  = max(cur, l - is(i - 1) + m - is(i) + r - is(i + 1));
        }
        if (i < n - 1)
        {
            a[i] = a[i + 1];
            cur  = max(cur, l - is(i - 1) + m - is(i) + r - is(i + 1));
        }
        a[i] = temp;
        cnt  = max(cnt, cur);
    }
    return ans - cnt;
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
        for (auto &ai : a)
            cin >> ai;
        cout << solve(a) << endl;
    }
    return 0;
}
