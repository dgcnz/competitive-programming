/** @file
 * @date                2021-01-29
 * @url                 https://atcoder.jp/contests/abc151/tasks/abc151_b
 * @tags                math, easy
 * @status              AC
 * @score               0
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       4
 * @coding_time         2
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Let $x$ be the score needed to achieve a total of $M$ points.
 *
 * $x = M * N  - \sum_{1}^{n - 1} a_i$
 *
 * If $x <= k$ then it's achievable, otherwise it's not.
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

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k, m;
    cin >> n >> k >> m;
    vi a(n - 1);
    for (auto &ai : a)
        cin >> ai;

    ll sum = accumulate(all(a), 0LL);

    ll x = max(m * n - sum, 0LL);
    x    = x > k ? -1 : x;
    cout << x << endl;
    return 0;
}
