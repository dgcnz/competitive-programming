/** @file
 * @date                2021-01-31
 * @url                 https://atcoder.jp/contests/abc181/tasks/abc181_a
 * @tags                easy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         2
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * If $n$ days pass, Takahashi will wear black if $n$ is odd and white
 * otherwise.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    cout << (n % 2 ? "Black" : "White") << endl;
    return 0;
}
