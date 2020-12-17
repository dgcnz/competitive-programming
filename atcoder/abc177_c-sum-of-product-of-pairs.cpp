/** @file
 * @date                2020-12-11
 * @url                 https://atcoder.jp/contests/abc177/tasks/abc177_c
 * @tags                math
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         3
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * By doing some algebra on the expression you will note that the contribution
 * of $a_i$ is:
 *
 * $$ a_i \times \sum_{j = i + 1}^{n} a_j $$
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

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll const MOD = 1e9 + 7;

    int n;
    cin >> n;
    vi a(n);
    read_n(begin(a), n);

    ll sfxsum = 0, ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        ans += a[i] * sfxsum;
        sfxsum += a[i];
        ans %= MOD, sfxsum %= MOD;
    }
    cout << ans << endl;
    return 0;
}
