/** @file
 * @date                2020-12-19
 * @url                 https://atcoder.jp/contests/abc186/tasks/abc186_b
 * @tags                easy, implementation
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         4
 * @time_complexity     O(hw)
 * @memory_complexity   O(hw)
 * @idea
 * To make all blocks the same height, make them the same height. as the
 * smallest block.
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
    int h, w;
    cin >> h >> w;

    ll minv = 1e9, sum = 0;
    for (int r = 0; r < h; ++r)
    {
        for (int c = 0; c < w; ++c)
        {
            ll arc;
            cin >> arc;
            minv = min(minv, arc);
            sum += arc;
        }
    }

    cout << sum - (h * w * minv) << endl;

    return 0;
}
