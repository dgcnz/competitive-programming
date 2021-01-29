/** @file
 * @date                2021-01-29
 * @url                 https://codeforces.com/contest/1476/problem/A
 * @tags                math
 * @status              AC
 * @score               0
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       4
 * @coding_time         5
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 *
 * Assume $k \geq n$, otherwise find the smallest multiple of $k$ that matches
 * that condition.
 *
 * We shall fill the $n$ elements with $floor(k / n)$ and then displace
 * uniformly the remainder over all posible $a_i$. In this way the remainder
 * counts for at most $1$.
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

int ceil(int a, int b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        k *= ceil(n, k);
        cout << k / n + ((k % n) != 0) << endl;
    }
    return 0;
}
