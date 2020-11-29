/** @file
 * @date                2020-11-28
 * @url                 https://atcoder.jp/contests/arc109/tasks/arc109_a
 * @tags                math, ad-hoc
 * @status              AC
 * @score               0
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       4
 * @coding_time         10
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * Divide problem on cases:
 *
 * 1. a == b. You will need to use a at least one corridor, so might as well use
 * just one.
 * 2. a > b and a < b. Two options:
 *   - Only use corridors (zig-zag).
 *   - Use one corridor and then stairs.
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
    int a, b, x, y;

    cin >> a >> b >> x >> y;

    if (a == b)
    {
        cout << x << endl;
    }
    else if (a > b)
        cout << min(x + (a - 1 - b) * y, x * ((a - b) * 2 - 1)) << endl;
    else
        cout << min(x + (b - a) * y, x * ((b - a) * 2 + 1)) << endl;

    return 0;
}
