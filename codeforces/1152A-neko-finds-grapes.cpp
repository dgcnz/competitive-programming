/** @file
 * @date                2021-03-25
 * @url                 https://url.com
 * @tags                math, sorting
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        000
 * @thinking_time       000
 * @coding_time         000
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 *
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vi acnt(2, 0), bcnt(2, 0);
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        acnt[ai % 2]++;
    }
    for (int i = 0; i < m; ++i)
    {
        int bi;
        cin >> bi;
        bcnt[bi % 2]++;
    }

    int ans = min(acnt[0], bcnt[1]) + min(acnt[1], bcnt[0]);
    cout << ans << endl;
    return 0;
}
