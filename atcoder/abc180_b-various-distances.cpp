/** @file
 * @date                2021-01-08
 * @url                 https://atcoder.jp/contests/abc180/tasks/abc180_b
 * @tags                implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Implementation.
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
using vi = vector<int>;

tuple<ll, double, ll> solve(vi x)
{
    vector<ll> ans(3, 0);
    for (auto xi : x)
    {
        ans[0] += abs(xi);
        ans[1] += ll(xi) * xi;
        ans[2] = max(ans[2], ll(abs(xi)));
    }
    return {ans[0], sqrt(ans[1]), ans[2]};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi x(n);
    for (auto &xi : x)
        cin >> xi;

    auto [ans0, ans1, ans2] = solve(x);
    cout << ans0 << endl;
    cout << setprecision(12) << fixed << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
