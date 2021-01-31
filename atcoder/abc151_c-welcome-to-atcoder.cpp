/** @file
 * @date                2021-01-29
 * @url                 https://atcoder.jp/contests/abc151/tasks/abc151
 * @tags                implementation
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         10
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
using ii = pair<int, int>;
using vi = vector<int>;

ii solve(vector<ii> sub_status, int n)
{
    vi problem(n, 0);
    ll penalty = 0;
    for (auto [p, s] : sub_status)
    {
        if (s == -1 and problem[p] <= 0)
        {
            problem[p] += s;
        }
        else if (s == +1)
        {
            if (problem[p] < 0)
                penalty += -problem[p];
            problem[p] = 1;
        }
    }
    ll score = count_if(all(problem), [](int x) { return x > 0; });
    return {score, penalty};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<ii> sub_status(m);
    for (int i = 0; i < m; ++i)
    {
        string si;
        cin >> sub_status[i].first >> si, sub_status[i].first--;
        sub_status[i].second = si == "AC" ? +1 : -1;
    }

    auto [score, penalty] = solve(sub_status, n);
    cout << score << " " << penalty << endl;
    return 0;
}
