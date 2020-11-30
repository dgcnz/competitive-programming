/** @file
 * @date                2020-11-30
 * @url                 https://codeforces.com/contest/1455/problem/A
 * @tags                math
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         1
 * @time_complexity     O(1)
 * @memory_complexity   O(n)
 * @idea
 * Observations:
 * 1. $f(f(x))$ is the same as stripping $x$ from all it's trailing zeros.
 * 2. $\frac{x}{f(f(x))}$ will always be the biggest power of $10$ that is a
 * factor of $x$.
 * 3. Finding all unique values of the formula is the same as finding all
 * possible powers of ten less or equal than $x$.
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
        string s;
        cin >> s;
        cout << isz(s) << endl;
    }
    return 0;
}
