/** @file
 * @date                2020-11-28
 * @url                 https://atcoder.jp/contests/arc109/tasks/arc109_c
 * @tags                dp
 * @status              AC
 * @score               2
 * @difficulty          3
 * @editorial           yes
 * @reading_time        3
 * @thinking_time       60
 * @coding_time         20
 * @time_complexity     O(n^2)
 * @memory_complexity   O(n^3)
 * @idea
 * - $dp(k, l)$: winner of tournament that starts at position $l$ in string and
 * has $2^k$ players.
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

int const NMAX = 1e2 + 5;

int    n, k;
char   dp[NMAX][NMAX];
string s;

ll binpow(ll a, ll b)
{
    a %= n;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % n;
        a = a * a % n;
        b >>= 1;
    }
    return res;
}

char op(char a, char b)
{
    // R : 1 P : 2 S :3
    if (a == b)
        return a;
    if ((a == 'P' and b == 'R') or (a == 'S' and (b == 'R' or b == 'P')))
        swap(a, b);

    if (a == 'R' and b == 'P')
        return b;
    else if (a == 'R' and b == 'S')
        return 'R';
    else // a = 'P' and b = 'S'
        return 'S';
}

char solve(int l, int w)
{
    char &ans = dp[w][l];
    if (ans)
        return ans;
    else if (w == 0)
        return s[l];
    else
    {
        return ans = op(solve(l, w - 1),
                        solve((l + binpow(2, w - 1)) % n, w - 1));
    }
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    cin >> n >> k >> s;
    cout << solve(0, k) << endl;
    return 0;
}
