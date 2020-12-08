/** @file
 * @date                2020-12-06
 * @url                 https://codeforces.com/contest/1450/problem/A
 * @tags                sortings, observation
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        0
 * @thinking_time       1
 * @coding_time         1
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Since the substring "trygub" doesn't follow a particular order
 * character-wise, we can sort the characters in our string to force an order.
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
        int    n;
        string s;
        cin >> n >> s;
        sort(all(s));
        cout << s << endl;
    }
    return 0;
}
