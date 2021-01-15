/** @file
 * @date                2021-01-14
 * @url                 https://codeforces.com/contest/1473/problem/C
 * @tags                constructive
 * @status              AC
 * @score               1
 * @difficulty          3
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       60
 * @coding_time         3
 * @time_complexity     O(n)
 * @memory_complexity   O(1)
 * @idea
 * This [comment](https://codeforces.com/blog/entry/86743#comment-748158)
 * explained it well.
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= 2 * k - n - 1; ++i)
            cout << i << " ";
        for (int i = k; i >= 2 * k - n; --i)
            cout << i << " ";
    }
    return 0;
}
