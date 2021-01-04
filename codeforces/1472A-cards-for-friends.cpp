/** @file
 * @date                2021-01-04
 * @url                 https://codeforces.com/contest/1472/problem/A
 * @tags                greedy, math
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       3
 * @coding_time         2
 * @time_complexity     O(\log{h} + \log{w})
 * @memory_complexity   O(1)
 * @idea
 * First note that the order of operations doesn't matter, and that if we have
 * currently $m$ identical pieces and we can make a certain cut $x$ (vertical or
 * horizontal), then we can make such cut for all $m$ pieces (duplicating its
 * number).
 *
 * We only need duplicate our count of sheets the total amount of cuts we can
 * make.
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

bool solve(int w, int h, int n)
{
    int ptwo = 1, m = 1;
    while (w % 2 == 0)
    {
        m *= 2;
        w /= 2;
        ptwo *= 2;
    }

    ptwo = 1;
    while (h % 2 == 0)
    {
        m *= 2;
        h /= 2;
        ptwo *= 2;
    }
    return m >= n;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        cout << (solve(w, h, n) ? "YES" : "NO") << endl;
    }
    return 0;
}
