/** @file
 * @date                2020-11-29
 * @url                 https://atcoder.jp/contests/abc049/tasks/arc065_a
 * @tags                backtracking
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        2
 * @thinking_time       5
 * @coding_time         8
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * - For position $i$, try all possible matches and backtrack if one doesn't
 * work.
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

int    n;
string s, opts[4] = {"dream", "dreamer", "erase", "eraser"};

bool solve(int i)
{
    if (i == n)
        return true;

    bool ans = false;
    for (auto const &opt : opts)
    {
        int m = isz(opt);
        if (m + i <= n and s.substr(i, m) == opt)
            ans = solve(i + m);
        if (ans)
            break;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    cin >> s;
    n = isz(s);

    cout << (solve(0) ? "YES" : "NO") << endl;

    return 0;
}
