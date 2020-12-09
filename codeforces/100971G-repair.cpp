/** @file
 * @date                2020-12-07
 * @url                 https://codeforces.com/gym/100971/problem/G
 * @tags                ad-hoc, implementation, brute_force
 * @status              AC
 * @score               0
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         20
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * 1. Try to fit sheet 1 on the corner of the bigger sheet.
 * 2. Try to fit sheet 2 on the remaining sheet from step 1.
 * 3. Rotate sheets if not possible.
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

inline bool fits(ii bigger, ii smaller)
{
    return bigger.first - smaller.first >= 0 and
           bigger.second - smaller.second >= 0;
}

inline ii rotate(ii x) { return {x.second, x.first}; }

vector<ii> cut(ii bigger, ii smaller)
{
    if (!fits(bigger, smaller))
        return {};

    vector<ii> ans;
    if (bigger.first - smaller.first != 0)
        ans.emplace_back(bigger.first - smaller.first, bigger.second);
    if (bigger.second - smaller.second != 0)
        ans.emplace_back(bigger.first, bigger.second - smaller.second);
    return ans;
}

bool solve(ii x0, ii x1, ii x2)
{
    for (auto x : cut(x0, x1))
        if (fits(x, x2) or fits(x, rotate(x2)))
            return true;
    for (auto x : cut(x0, rotate(x1)))
        if (fits(x, x2) or fits(x, rotate(x2)))
            return true;
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ii x0, x1, x2;
    cin >> x0.first >> x0.second >> x1.first >> x1.second >> x2.first >>
        x2.second;
    cout << (solve(x0, x1, x2) ? "YES" : "NO") << endl;

    return 0;
}
