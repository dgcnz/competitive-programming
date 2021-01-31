/** @file
 * @date                2021-01-15
 * @url                 https://codeforces.com/contest/808/problem/D
 * @tags                greedy, binary_search, implementation
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         15
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/52010).
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

bool solve(vi a)
{
    ll target = accumulate(all(a), 0LL);
    if (target & 1)
        return false;
    target /= 2;

    for (int i = 0; i < 2; ++i)
    {
        ll      sum = 0;
        set<ll> unique;
        for (auto ai : a)
        {
            sum += ai;
            unique.insert(ai);
            if (unique.find(sum - target) != unique.end())
                return true;
        }
        reverse(all(a));
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);

    for (auto &ai : a)
        cin >> ai;

    cout << (solve(a) ? "YES" : "NO") << endl;

    return 0;
}
