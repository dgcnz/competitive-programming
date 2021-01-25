/** @file
 * @date                2021-01-25
 * @url                 https://codeforces.com/contest/1475/problem/G
 * @tags                dp, number_theory
 * @status              AC
 * @score               2
 * @difficulty          4
 * @editorial           no
 * @reading_time        1
 * @thinking_time       40
 * @coding_time         30
 * @time_complexity     O(a_{max} \log{a_max})
 * @memory_complexity   O(a_{max})
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/87188)
 * [Comment](https://codeforces.com/blog/entry/87161?#comment-753182)
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
    int const AMAX = *max_element(all(a)) + 1, n = a.size();

    vi dp(AMAX, 0), cnt(AMAX, 0);

    for (auto ai : a)
        cnt[ai]++;

    for (int x = 1; x < AMAX; ++x)
    {
        dp[x] += cnt[x];
        for (int y = 2 * x; y < AMAX; y += x)
            dp[y] = max(dp[y], dp[x]);
    }
    return n - *max_element(all(dp));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vi a(n);
        for (auto &ai : a)
            cin >> ai;

        cout << solve(a) << endl;
    }
    return 0;
}
