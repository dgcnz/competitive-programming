/** @file
 * @date                2021-01-29
 * @url                 https://codeforces.com/contest/1476/problem/B
 * @tags                greedy
 * @status              AC
 * @score               1
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         30
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * The problem tells us that for each $i > 0$ we need:
 *
 * $$
 * \frac{p_i}{psum_{i- 1}} \leq \frac{k}{100}
 * $$
 *
 * Where $psum_{i}$ is the prefix sum of $p$ up to $i$.
 *
 * To avoid floating errors, we want the following condition:
 *
 * $$
 * \frac{100 p_i}{k} \leq psum_{i-1}
 * $$
 *
 * Furthermore, note that it is always optimal to increment $p_0$, as it will
 * necessarily decrease all inflation rates.
 *
 * So, for each $i$ we can greedily try to increase $p_0$ until the condition
 * holds.
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

ll solve(vector<ll> p, int k)
{
    int n   = p.size();
    ll  sum = p.front(), ans = 0;
    for (int i = 1; i < n; ++i)
    {
        ll dif = ceil(100 * p[i], k) - (sum + ans);
        if (dif > 0)
            ans += dif;
        sum += p[i];
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<ll> p(n);
        for (auto &pi : p)
            cin >> pi;

        cout << solve(p, k) << endl;
    }
    return 0;
}
