/** @file
 * @date                2021-01-30
 * @url                 https://atcoder.jp/contests/abc190/tasks/abc190_b
 * @tags                implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * For each monster test if it will yield damage.
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
    int n, s, d;
    cin >> n >> s >> d;

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x < s and y > d)
            ans += y;
    }
    cout << (ans > 0 ? "Yes" : "No") << endl;

    return 0;
}
