/** @file
 * @date                2021-01-31
 * @url                 https://atcoder.jp/contests/abc181/tasks/abc181_c
 * @tags                math, brute_force
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       7
 * @coding_time         7
 * @time_complexity     O(n^3)
 * @memory_complexity   O(n)
 * @idea
 * Given three points, we can check if they lie on the same line by testing if
 * their slope is the same. We shall do some algebra first to work with integers
 * and avoid precision errors.
 *
 * Using this fact, we can try all triplets of points to see if they fulfill
 * this condition.
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

bool solve(vector<ii> points)
{
    int n = points.size();
    sort(all(points));
    for (int i = 0; i < n - 2; ++i)
    {
        auto [x1, y1] = points[i];
        for (int j = i + 1; j < n - 1; ++j)
        {
            auto [x2, y2] = points[j];
            for (int k = j + 1; k < n; ++k)
            {
                auto [x3, y3] = points[k];
                if ((x2 - x1) * (y3 - y2) == (x3 - x2) * (y2 - y1))
                    return true;
            }
        }
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ii> points(n);

    for (auto &[x, y] : points)
        cin >> x >> y;

    cout << (solve(points) ? "Yes" : "No") << endl;
    return 0;
}
