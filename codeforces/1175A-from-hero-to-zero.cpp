/** @file
 * @date                2020-11-27
 * @url                 https://codeforces.com/contest/1175/problem/A
 * @tags                number_theory, euclidean_algorithm
 * @status              AC
 * @score               3
 * @difficulty          1
 * @editorial           no
 * @reading_time        2
 * @thinking_time       4
 * @coding_time         5
 * @time_complexity     O( \log{n})
 * @memory_complexity   O(1)
 * @idea
 * Intuition tells us that it is always better to divide by $k$ whenever
 * possible. Following this reasoning, the procedure is as follows:
 *
 * For a number $n = d_1 * k + r_1$, subtract $r_1$ and perform one division.
 * Our new number will be $d_1$. Proceed until 0.
 *
 * One way to think about the problem is to convert the number $n$ to base-$k$.
 * The problem would then be to wipe out all numbers to get a sequence of zeros,
 * by subtracting $1$ or shifting left one position if the last position is $0$.

 * I think it becomes more evident why the aforementioned strategy is optimal.
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

ll solve(ll n, ll k)
{
    if (n == 0)
        return 0;
    ll r = n % k, d = n / k;
    return r + (d == 0 ? 0 : 1 + solve(d, k));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}
