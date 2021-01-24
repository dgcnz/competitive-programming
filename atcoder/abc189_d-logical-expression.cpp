/** @file
 * @date                2021-01-23
 * @url                 https://atcoder.jp/contests/abc189/tasks/abc189_d
 * @tags                dp
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Let's define the following dps:
 *
 * $dp_1(i)$ : Number of ways for the expression $x_0,...x_i$ to be true with
 * the given logical operators up to the $i$th.
 *
 * $dp_0(i)$ : Number of ways for the expression $x_0,...x_i$ to be false with
 * the given logical operators up to the $i$th.
 *
 * In $dp_1$:
 *
 * For the case where the $i$th logical operator, $op$, $x_{i-1} op x_i$, is an
 * `AND`, we need the expression $x_0,...x_{i-1}$ to yield true.
 *
 * For the case where the $i$th logical operator, $op$, $x_{i-1} op x_i$, is an
 * `OR`, the expression $x_0,...x_{i-1}$ can yield true (in which case $x_i$ can
 * be either true or false) or false (in which case $x_i$ must be true).
 *
 * One can similarly define $dp_0$.
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
using ll  = long long;
using ii  = pair<int, int>;
using vi  = vector<int>;
using vll = vector<ll>;

ll solve(vi a)
{
    int         n = isz(a);
    vector<vll> dp(n + 1, vll(2, 0));

    dp[0][0] = dp[0][1] = 1;

    for (int i = 1; i <= n; ++i)
    {
        if (a[i - 1]) // AND
        {
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = 2 * dp[i - 1][0] + dp[i - 1][1];
        }
        else // OR
        {
            dp[i][1] = dp[i - 1][0] + 2 * dp[i - 1][1];
            dp[i][0] = dp[i - 1][0];
        }
    }
    return dp[n][1];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &ai : a)
    {
        string s;
        cin >> s;
        ai = s == "AND";
    }

    cout << solve(a) << endl;
    return 0;
}
