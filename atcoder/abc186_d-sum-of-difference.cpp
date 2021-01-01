/** @file
 * @date                2020-12-19
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
 * Two observations:
 * - $|x - y| = |y - x|$.
 * - Each $a_i$ is paired with all other elements $a_j$, $i!=j$.
 *
 * This allows us to reorder the elements, both in position and in the operand.
 *
 * Sort the array non-decreasingly. In this way we won't have to worry about
 * possible negative values:
 *
 * $$ \sum_{i=n}^{1} (i \times a_i -  \sum_{j = 1}^{i - 1} a_j) $$
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io.hpp>
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

    vector<ll> a(n), pa(n);
    read_n(begin(a), n);
    sort(all(a));
    partial_sum(all(a), begin(pa));

    ll ans = 0;
    for (int i = n - 1; i >= 1; --i)
        ans += i * a[i] - pa[i - 1];
    cout << ans << endl;

    return 0;
}
