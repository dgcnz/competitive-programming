/** @file
 * @date                2020-12-18
 * @url                 https://atcoder.jp/contests/abc157/tasks/abc157_b
 * @tags                implementation, easy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         15
 * @time_complexity     O(n)
 * @memory_complexity   O(1)
 * @idea
 * Check horizontally, vertically and in both diagonals.
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
    array<array<int, 3>, 3> bingo;

    for (auto &row : bingo)
        for (auto &val : row)
            cin >> val;

    int n;
    cin >> n;

    while (n--)
    {
        int bi;
        cin >> bi;
        for (auto &row : bingo)
            for (auto &val : row)
                if (val == bi)
                    val = 0;
    }

    vi ver_cnt(3, 0), hor_cnt(3, 0), diag_cnt(2, 0);

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (bingo[i][j] == 0)
                ver_cnt[j]++, hor_cnt[i]++;

    for (int i = 0; i < 3; ++i)
    {
        if (bingo[i][i] == 0)
            diag_cnt[0]++;
        if (bingo[i][3 - i - 1] == 0)
            diag_cnt[1]++;
    }

    bool ans = any_of(all(ver_cnt), [](int cnt) { return cnt == 3; }) |
               any_of(all(hor_cnt), [](int cnt) { return cnt == 3; }) |
               any_of(all(diag_cnt), [](int cnt) { return cnt == 3; });
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
