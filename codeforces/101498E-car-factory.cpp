/** @file
 *
 * @url                 https://codeforces.com/gym/101498/problem/E
 * @tags                math
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       3
 * @coding_time         2
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 *  - The answer is $k$ + the time the last car is waiting.
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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << (n - 1) + k << endl;
    }
    return 0;
}
