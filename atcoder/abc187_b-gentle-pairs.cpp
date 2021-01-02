/** @file
 * @date                2021-01-02
 * @url                 https://atcoder.jp/contests/abc187/tasks/abc187_b
 * @tags                brute_force
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        2
 * @thinking_time       15
 * @coding_time         10
 * @time_complexity     O(n^2)
 * @memory_complexity   O(n)
 * @idea
 * The formula to compute the slope given two points $(x_1, y_1)$ and
 * $(x_2, y_2)$ is:
 *
 * $$ m = \frac{y_2 - y_1}{x_2 - x_1}$$
 *
 * The problem tells you that:
 *
 * $$ -1 \leq \frac{y_2 - y_1}{x_2 - x_1} \leq 1$$
 *
 * Or equivalently:
 *
 * $$ | y_2 - y_1 |  \leq y_2 - y_1 $$
 *
 * Try all pairs and check if such condition holds. Don't forget to enforce an
 * order to ease implementation (sort points by $x$-coordinate).
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

int solve(vector<ii> xy)
{
    int n = isz(xy), ans = 0;
    sort(all(xy));
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            auto [xi, yi] = xy[i];
            auto [xj, yj] = xy[j];
            ans += (abs(yj - yi) <= (xj - xi));
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ii> xy(n);
    for (auto &[x, y] : xy)
        cin >> x >> y;

    cout << solve(xy) << endl;
    return 0;
}
