/** @file
 * @date                2020-12-26
 * @url                 https://codeforces.com/problemset/problem/284/A
 * @tags                brute_force, modulo
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         10
 * @time_complexity     O(p^2)
 * @memory_complexity   O(1)
 * @idea
 * Brute force and test all $x < p$. Check this
 * [editorial](https://codeforces.com/blog/entry/7037) for a more mathy
 * solution.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(int p)
{
    int ans = 0;
    for (int x = 1; x < p; ++x)
    {
        bool flag = true;
        int  y    = x % p;
        for (int i = 1; i <= p - 2; ++i)
        {
            if (y == 1)
            {
                flag = false;
                break;
            }
            y = (y * x) % p;
        }
        if (y % p != 1)
            flag = false;
        ans += flag;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int p;
    cin >> p;
    cout << solve(p) << endl;
    return 0;
}
