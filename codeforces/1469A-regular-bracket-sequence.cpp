/** @file
 * @date                2020-12-28
 * @url                 https://codeforces.com/contest/1469/problem/A
 * @tags                greedy, observation
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         1
 * @time_complexity     O(1)
 * @memory_complexity   O(n)
 * @idea
 * There are two cases in which it is impossible to construct a valid sequence:
 * 1. The length of the sequence is odd.
 * 2. A parenthesis is unmatchable: `)....` or `....(`.
 *
 * To understand why is it otherwise always possible, let $t$ be the string that
 * results from greedy-matching the existing parenthesis (matching a parenthesis
 * with the closest interrogation symbol). Such a string will be empty or be an
 * even-length sequence of `?`, which is trivially regular (first half `(` and
 * second half `)`).
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

bool solve(string s)
{
    if (s[0] == ')' or s.back() == '(')
        return false;

    return (isz(s) - 2) % 2 == 0;
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
        cout << (solve(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
