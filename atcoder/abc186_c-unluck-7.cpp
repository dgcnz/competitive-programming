/** @file
 * @date                2020-12-19
 * @url                 https://atcoder.jp/contests/abc186/tasks/abc186_c
 * @tags                brute_force, math
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       11
 * @coding_time         5
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(1)
 * @idea
 * Try all numbers from `[1, n]` and check if they contain $7$ in their octal or
 * decimal representation.
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

bool bad(int n, int base)
{
    while (n)
    {
        if ((n % base) == 7)
            return true;
        n /= base;
    }
    return false;
}

int solve(int n)
{
    int ans = n;
    for (int i = n; i > 0; --i)
        if (bad(i, 10) or bad(i, 8))
            ans--;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
