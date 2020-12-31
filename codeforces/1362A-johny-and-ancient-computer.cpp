/** @file
 * @date                2020-12-30
 * @url                 https://codeforces.com/contest/1362/problem/A
 * @tags                math, implementation
 * @status              AC
 * @score               1
 * @difficulty          2
 * @editorial           no
 * @reading_time        2
 * @thinking_time       10
 * @coding_time         5
 * @time_complexity     O(\log{\max(a, b)})
 * @memory_complexity   O(1)
 * @idea
 * Without loss of generality, say $a \geq b$. We'll try to make $b$ into $a$ by
 * multiplying it by $2$, $4$ and $8$.
 *
 * Note that this is only possible if $a = b \times 2^k$, for some integer $k$.
 * We verify that, and then decompose $2^k$ into $8$s, $4$s and $2$s.
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

int solve(ll a, ll b)
{
    if (a % b)
        return -1;
    ll twok = a / b;

    int k = 0;
    while (twok != 1)
    {
        if (twok % 2)
            return -1;
        twok /= 2;
        k++;
    }

    int ans = 0;
    ans += k / 3;
    k %= 3;
    ans += k / 2;
    k %= 2;
    ans += k / 1;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a < b)
            swap(a, b);

        cout << solve(a, b) << endl;
    }
    return 0;
}
