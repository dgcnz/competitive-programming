/** @file
 * @date                2021-01-23
 * @url                 https://atcoder.jp/contests/abc182/tasks/abc182_b
 * @tags                brute_force, number_theory, implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         5
 * @time_complexity     O(a_{max} \times n)
 * @memory_complexity   O(n)
 * @idea
 * Count number of elements divisible by $k$ for each $2 \geq k \geq a_{max}$.
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

int solve(vi a)
{
    int amax = *max_element(all(a));

    ii ans = {0, 0};

    for (int k = 2; k <= amax; ++k)
    {
        int cur = count_if(all(a), [k](int ai) { return ai % k == 0; });
        ans     = max(ans, {cur, k});
    }
    return ans.second;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi a(n);

    for (auto &ai : a)
        cin >> ai;

    cout << solve(a) << endl;
    return 0;
}
