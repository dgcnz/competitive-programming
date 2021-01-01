/** @file
 * @date                2020-12-24
 * @url
 * https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=516
 * @tags                implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         3
 * @time_complexity     O(|n|)
 * @memory_complexity   O(|n|)
 * @idea
 * Same as converting from binary to decimal but with $2^{k + 1} - 1$ as factor.
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
    string n;
    while (cin >> n and n != "0")
    {
        int m = isz(n), x = 0;

        reverse(all(n));
        for (int i = 0; i < m; ++i)
            x += ((1LL << (i + 1)) - 1) * (n[i] - '0');

        cout << x << endl;
    }
    return 0;
}
