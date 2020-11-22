/** @file
 *
 * @url                 https://codeforces.com/gym/101498/problem/A
 * @tags                sorting, data-structures
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         5
 * @time_complexity     O(n \log(n))
 * @memory_complexity   O(n)
 * @idea
 *  - Maintain a map that stores the frequency count.
 *  - Find frequency with biggest count.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> counter;
        while (n--)
        {
            string s;
            int    freq;
            cin >> s >> freq;
            counter[freq]++;
        }

        int ans = max_element(all(counter), [](auto a, auto b) {
                      if (a.second == b.second)
                          return a.first > b.first;
                      return a.second < b.second;
                  })->first;
        cout << ans << endl;
    }
    return 0;
}
