/** @file
 * @date                2021-01-02
 * @url                 https://atcoder.jp/contests/abc187/tasks/abc187_d
 * @tags                greedy, sorting
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         10
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Greedy pick elements ordered by $2a + b$. Intuitively, we want to maximize
 * both the contribution of a pick to oneself, $a + b$, and the loss from the
 * other, $a$. Also, check [this](https://codeforces.com/blog/entry/86297).
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
using ii = pair<ll, ll>;
using vi = vector<int>;

int solve(vector<ii> ab)
{
    auto cmp = [](ii x, ii y) {
        auto [a1, b1] = x;
        auto [a2, b2] = y;
        return 2 * a1 + b1 > 2 * a2 + b2;
    };
    auto sum_first = [](ll acc, ii x) -> ll { return acc + x.first; };

    sort(all(ab), cmp);
    ll  atot = accumulate(all(ab), 0LL, sum_first), btot = 0;
    int ans = 0;
    for (auto [a, b] : ab)
    {
        btot += a + b;
        atot -= a;
        ans++;
        if (btot > atot)
            break;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> ab(n);

    for (auto &[a, b] : ab)
        cin >> a >> b;

    cout << solve(ab) << endl;

    return 0;
}
