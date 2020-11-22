/** @file
 *
 * @url                 https://codeforces.com/gym/101498/problem/C
 * @tags                implementation, math
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         2
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 *  - Get index of minimum element.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    string ans[3] = {"First", "Second", "Third"};
    int    roads[3];

    while (t--)
    {
        cin >> roads[0] >> roads[1] >> roads[2];
        cout << ans[distance(roads, min_element(roads, roads + 3))] << endl;
    }
    return 0;
}
