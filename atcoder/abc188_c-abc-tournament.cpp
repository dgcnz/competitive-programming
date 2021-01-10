/** @file
 * @date                2021-01-10
 * @url                 https://atcoder.jp/contests/abc188/tasks/abc188_c
 * @tags                implementation, observation, greedy
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         5
 * @time_complexity     O(2^n)
 * @memory_complexity   O(1)
 * @idea
 * The two finalist will be the ones that have maximum rating in both halves of
 * the tournament.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    n = (1LL << n);

    ii ansl = {0, 0}, ansr = {0, 0};
    for (int i = 0; i < n / 2; ++i)
    {
        int ai;
        cin >> ai;
        ansl = max(ansl, {ai, i});
    }

    for (int i = n / 2; i < n; ++i)
    {
        int ai;
        cin >> ai;
        ansr = max(ansr, {ai, i});
    }

    ii ans = min(ansl, ansr);
    cout << ans.second + 1 << endl;

    return 0;
}
