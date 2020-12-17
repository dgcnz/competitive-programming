/** @file
 * @date                2020-12-11
 * @url                 https://atcoder.jp/contests/abc177/tasks/abc177_b
 * @tags                brute_force
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       3
 * @coding_time         5
 * @time_complexity     O(n^2)
 * @memory_complexity   O(n)
 * @idea
 * Try all possible positions for string $T$ and keep the minimum number of
 * differences for all of them.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s, t;
    cin >> s >> t;

    int n = isz(s), m = isz(t), ans = m;
    for (int i = 0; i <= n - m; ++i)
    {
        int cur = m;
        for (int j = 0; j < m; ++j)
            if (t[j] == s[i + j])
                cur--;
        ans = min(ans, cur);
    }

    cout << ans << endl;
    return 0;
}
