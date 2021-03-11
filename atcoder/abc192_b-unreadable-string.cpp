/** @file
 * @date                2021-02-20
 * @url                 https://atcoder.jp/contests/abc192/tasks/abc192_b
 * @tags                implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         1
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 *
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

bool hard(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i += 2)
        if (not islower(s[i]))
            return false;
    for (int i = 1; i < n; i += 2)
        if (not isupper(s[i]))
            return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;
    cout << (hard(s) ? "Yes" : "No") << endl;
    return 0;
}
