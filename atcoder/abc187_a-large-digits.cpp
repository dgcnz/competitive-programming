/** @file
 * @date                2021-01-02
 * @url                 https://atcoder.jp/contests/abc187/tasks/abc187_a
 * @tags                easy, implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       2
 * @coding_time         5
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 *
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

int d(char c) { return c - '0'; }

int s(string x) { return d(x[0]) + d(x[1]) + d(x[2]); }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string a, b;
    cin >> a >> b;

    int sa = s(a), sb = s(b);
    cout << (sa >= sb ? sa : sb) << endl;
    return 0;
}
