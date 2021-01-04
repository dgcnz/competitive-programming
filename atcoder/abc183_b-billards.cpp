/** @file
 * @date                2021-01-04
 * @url                 https://atcoder.jp/contests/abc183/tasks/abc183_b
 * @tags                math, geometry
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         5
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * With a bit of geo, we can define the following two equations for the
 * $x$-coordinate of the incident point, $A_x$.
 *
 * $$A_x = S_x + S_y \frac{\cos{\alpha}}{\sin{\alpha}}$$
 *
 * $$A_x = G_x - G_y \frac{\cos{\alpha}}{\sin{\alpha}}$$
 *
 * We can solve for $\alpha$ and then replace it on one of those equations to
 * get the answer.
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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double alpha = atan(double(y1 + y2) / double(x2 - x1));
    cout << setprecision(12) << fixed << x1 + y1 * cos(alpha) / sin(alpha)
         << endl;
    return 0;
}
