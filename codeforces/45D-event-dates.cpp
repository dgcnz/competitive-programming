/** @file
 * @date                2021-01-15
 * @url                 https://codeforces.com/contest/45/problem/D
 * @tags                greedy
 * @status              AC
 * @score               2
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         10
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * This is a slight modification of the classical greedy interval scheduling.
 *
 * Sort intervals, $l, r$, based on their maximum ending time, $r$.
 * We can greedily pick the $ith$ interval's position by the first $j \geq l$
 * that is free.
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
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;
using vi  = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;

    cin >> n;
    vector<iii> a(n);

    int maxr = 0, i = 0;
    for (auto &[r, l, ix] : a)
    {
        cin >> l >> r;
        ix   = i++;
        maxr = max(maxr, r);
    }

    sort(all(a));

    vi used(maxr + 1, 0), ans(n);
    for (auto [r, l, i] : a)
    {
        while (used[l])
            l++;
        ans[i]  = l;
        used[l] = true;
    }

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
