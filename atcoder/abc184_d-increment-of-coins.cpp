/** @file
 * @date                2020-12-11
 * @url                 https://atcoder.jp/contests/abc184/tasks/abc184_d
 * @tags                dp, expected_value, probability
 * @status              AC
 * @score               3
 * @difficulty          4
 * @editorial           yes
 * @reading_time        2
 * @thinking_time       60
 * @coding_time         5
 * @time_complexity     O(n^3)
 * @memory_complexity   O(n^3)
 * @idea
 * I'm kinda :brick: at Probability, so here's the
 * [Editorial](https://atcoder.jp/contests/abc184/editorial/371).
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;

int const NMAX = 100 + 1;

double dp[NMAX][NMAX][NMAX];

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    for (int x = 99; x >= 0; --x)
    {
        for (int y = 99; y >= 0; --y)
        {
            for (int z = 99; z >= 0; --z)
            {
                double d    = x + y + z;
                dp[x][y][z] = x / d * (dp[x + 1][y][z] + 1) +
                              y / d * (dp[x][y + 1][z] + 1) +
                              z / d * (dp[x][y][z + 1] + 1);
            }
        }
    }
    cout << setprecision(12) << fixed << dp[a][b][c] << endl;

    return 0;
}
