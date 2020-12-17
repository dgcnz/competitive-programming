/** @file
 * @date                2020-12-12
 * @url                 https://atcoder.jp/contests/abc176/tasks/abc176_b
 * @tags                easy
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
 * Check if the sum of digits is multiple of $9$.
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
    string n;
    cin >> n;

    ll sum =
        accumulate(all(n), 0LL, [](ll acc, char c) { return acc + (c - '0'); });
    cout << (sum % 9 == 0 ? "Yes" : "No") << endl;

    return 0;
}
