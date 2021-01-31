/** @file
 * @date                2021-01-23
 * @url                 https://atcoder.jp/contests/abc189/tasks/abc189_a
 * @tags                easy, implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         2
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * Check if three values are equal.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;

    cout << (s[0] == s[1] and s[1] == s[2] ? "Won" : "Lost") << endl;
    return 0;
}
