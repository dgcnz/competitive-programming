/** @file
 *
 * @url                 https://codeforces.com/gym/101498/problem/B
 * @tags                greedy
 *
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 *
 * @reading_time        1
 * @thinking_time       2
 * @coding_time         4
 * @debug_time          2
 *
 * @time_complexity     [O(n))
 * @memory_complexity   [O(n)]
 * @idea
 *  - Greedily match the characters of the second string to the first string.
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
        string a, b;
        vi     bcnt(26);
        cin >> a >> b;

        for (auto ch : b)
            bcnt[ch - 'a']++;

        int i = 0, n = isz(a);
        while (i < n and bcnt[a[i] - 'a'] > 0)
        {
            bcnt[a[i] - 'a']--;
            ++i;
        }
        cout << i << endl;
    }
    return 0;
}
