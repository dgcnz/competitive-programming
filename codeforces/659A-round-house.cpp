/** @file
 * @date                2020-12-25
 * @url                 https://codeforces.com/contest/659/problem/A
 * @tags                easy, modulo
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         4
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * $$ a + b \mod n$$
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
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
    int n, a, b;
    cin >> n >> a >> b;
    cout << (((a - 1 + b) % n) + n) % n + 1 << endl;
    return 0;
}
