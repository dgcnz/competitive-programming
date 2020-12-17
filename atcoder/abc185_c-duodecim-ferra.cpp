/** @file
 * @date                2020-12-13
 * @url                 https://atcoder.jp/contests/abc185/tasks/abc185_c
 * @tags                combinatorics, dp
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         40
 * @time_complexity     O(l^2)
 * @memory_complexity   O(l^2)
 * @idea
 * Compute the number of ways to cut a log of width $l$, $C(l - 1, 11)$.
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
    int l;
    cin >> l;

    vector<vector<ll>> C(l + 1, vector<ll>(l + 1, 0));
    C[0][0] = 1;
    for (int n = 1; n <= l; ++n)
    {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
    cout << C[l - 1][11] << endl;

    return 0;
}
