/** @file
 * @date                2020-12-25
 * @url                 https://codeforces.com/problemset/problem/742/A
 * @tags                easy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         1
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * Note that $1378^n \equiv 8^n \mod 10$. Furthermore, for $n >= 1$, you might
 * notice a pattern with $n$ if you list answers for small numbers. They repeat
 * with a period of 4, so just hardcode them.
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
    int n, ans[4] = {8, 4, 2, 6};
    cin >> n;
    if (n == 0)
        cout << 1 << endl;
    else
        cout << ans[(n - 1) % 4] << endl;
    return 0;
}
