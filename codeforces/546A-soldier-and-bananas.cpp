/** @file
 * @date                https://codeforces.com/problemset/problem/546/A
 * @url                 https://url.com
 * @tags                easy, summation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         4
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * Reduce summation to closed form and solve the equation.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int k, n, w;
    cin >> k >> n >> w;
    int x = max(k * (w * (w + 1)) / 2 - n, 0);
    cout << x << endl;
    return 0;
}
