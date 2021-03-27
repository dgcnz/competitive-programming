/** @file
 * @date                2021-03-25
 * @url                 https://url.com
 * @tags                math, sorting
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        000
 * @thinking_time       000
 * @coding_time         000
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 *
 *
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

int check(int x)
{
    return __builtin_clz(x) == sizeof(int) * 8 - __builtin_popcount(x);
}

pair<int, vi> solve(int x)
{
    int ops = 0;
    vi  ans;
    while (ops <= 40)
    {
        if (check(x))
            break;

        int n = sizeof(int) * 8 - __builtin_clz(x);
        x ^= (1 << n) - 1;
        ans.push_back(n);
        ops++;
        if (check(x))
            break;
        x++;
        ops++;
    }
    return {ops, ans};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int x;
    cin >> x;

    auto [n, ans] = solve(x);
    cout << n << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
