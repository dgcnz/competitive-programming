/** @file
 * @date                2020-11-21
 * @url                 https://codeforces.com/gym/101498/problem/H
 * @tags                greedy
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       3
 * @coding_time         8
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 *  - Note that there are 2 ways in which no solutions exist:
 *      1. n > 1 and s == 1, where placing 1 on both ends would exceed s.
 *      2. otherwise, when s exceeds placing 9 on all places.
 *  - The first case can be handled by a if guard.
 *  - Note that the most significant digits have greater effect in maximizing
 * the palindrome.
 *  - The strategy would then be to greedily maximize from i=0 to n/2.
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

string solve(int n, int s)
{
    if (n > 1 and s == 1)
        return "-1";

    string ans(n, '0');
    for (int i = 0, mid = n / 2; i < mid; ++i)
    {
        for (int d = 9; d >= 0; --d)
        {
            if (s - 2 * d >= 0)
            {
                ans[i] = ans[n - 1 - i] = d + '0';
                s -= 2 * d;
                break;
            }
        }
    }
    if (n % 2 == 1)
    {
        for (int d = 9; d >= 0; --d)
        {
            if (s - d >= 0)
            {
                ans[n / 2] = d + '0';
                s -= d;
                break;
            }
        }
    }
    return s == 0 ? ans : "-1";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        cout << solve(n, s) << endl;
    }
    return 0;
}
