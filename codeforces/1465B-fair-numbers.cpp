/** @file
 * @date                2020-12-20
 * @url                 https://codeforces.com/contest/1465/problem/B
 * @tags                brute_force, observation
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         3
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * Note that the minimum fair integer $x$ such that $n \leq x$ is at most
 * $lcm(1, 2, ..., 9)$ steps away ($2520$). This is the period of fair numbers
 * that contain all single non-zero digits, therefore, the maximum period.
 *
 * Brute force approach:
 * - Test if number is fair, if not increment it and try again until it is.
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

bool fair(ll n)
{
    ll x = n;
    while (x != 0)
    {
        int d = x % 10;
        if (d and n % d)
            return false;
        x /= 10;
    }
    return true;
}

ll solve(ll n)
{
    while (not fair(n))
        ++n;
    return n;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
