/** @file
 * @date                2021-01-12
 * @url                 https://codeforces.com/contest/1368/problem/C
 * @tags                constructive
 * @status              AC
 * @score               0
 * @difficulty          2
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(1)
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/79027).
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
    int n;

    cin >> n;
    vector<ii> points = {{1, 0}, {0, 1}, {1, 1}};
    cout << (n + 1) * 3 + 1 << endl;

    cout << 0 << " " << 0 << endl;

    for (int i = 0; i <= n; ++i)
        for (auto &[x, y] : points)
            cout << x++ << " " << y++ << endl;

    return 0;
}
