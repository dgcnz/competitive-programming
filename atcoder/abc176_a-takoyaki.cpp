/** @file
 * @date                2020-12-12
 * @url                 https://atcoder.jp/contests/abc176/tasks/abc176_a
 * @tags                easy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         1
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * The answer is:
 * $$t \times ceil(\frac{n}{x})$$
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;

int ceil(int a, int b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, x, t;
    cin >> n >> x >> t;

    cout << t * ceil(n, x) << endl;

    return 0;
}
