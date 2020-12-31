/** @file
 * @date                2020-12-30
 * @url                 https://codeforces.com/contest/1466/problem/C
 * @tags                greedy
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
 * Note that you only have to worry about substrings of the form: `xx` or `xyx`.
 *
 * Strategy: if element in in a substring of one of the previous form, change it
 * so that it doesn't (don't forget to check that it won't form another
 * palindrome).
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

int solve(string s)
{
    int n = isz(s), ans = 0;
    s += "{{";
    vector<vector<bool>> prohibited(n + 2, vector<bool>(27, false));

    for (int i = 0; i < n; ++i)
    {
        if (prohibited[i][s[i] - 'a'])
        {
            for (int ch = 0; ch < 26; ++ch)
            {
                if (!prohibited[i][ch] and s[i + 1] != (ch + 'a') and
                    s[i + 2] != (ch + 'a'))
                {
                    s[i] = ch + 'a';
                    break;
                }
            }
            ans++;
        }

        prohibited[i + 1][s[i] - 'a'] = prohibited[i + 2][s[i] - 'a'] = true;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
