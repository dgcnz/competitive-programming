/** @file
 * @date                2021-01-10
 * @url                 https://atcoder.jp/contests/abc188/tasks/abc188_b
 * @tags                implementation, easy
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         2
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Straightforward implementation of dot product.
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
using vi = vector<ll>;

bool solve(vi a, vi b)
{
    vi ans(a.size());
    transform(all(a), begin(b), begin(ans), multiplies<ll>());
    return accumulate(all(ans), 0LL) == 0;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi a(n), b(n);

    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;

    cout << (solve(a, b) ? "Yes" : "No") << endl;
    return 0;
}
