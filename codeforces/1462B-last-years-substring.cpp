/** @file
 * @date                2020-12-15
 * @url                 https://codeforces.com/contest/1462/problem/B
 * @tags                implementation, strings
 * @status              AC
 * @score               0
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       4
 * @coding_time         3
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * There are three successful cases for a string $s$:
 * 1. $s$ = `2020`
 * 2. `2020` is a prefix of $s$
 * 3. `2020` is a suffix of $s$
 *
 * To see if $s$ matches one of these cases, compute the longest common prefix
 * between $s$ and `2020` and the longest common suffix between $s$ and `2020`.
 * If the sum of those answers is greater or equal than $4$, then it means that
 * I can combine them together (removing the excess in the middle) and get
 * $2020$.
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

bool solve(string s)
{
    int    n   = isz(s);
    string sub = "2020";
    if (s == sub)
        return true;

    int pre = 0, suf = 0;
    while (pre < 4 and s[pre] == sub[pre])
        ++pre;

    while (suf < 4 and s[n - suf - 1] == sub[4 - suf - 1])
        ++suf;

    return pre + suf >= 4;
}

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
        cout << (solve(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
