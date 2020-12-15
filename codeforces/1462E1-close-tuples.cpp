/** @file
 * @date                2020-12-15
 * @url                 https://codeforces.com/contest/1462/problem/E1
 * @tags                sorting, combinatorics, binary_search
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         5
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * See post for E2, this is just a special case of it.
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

ll C2(ll n)
{
    if (n < 2)
        return 0;
    return (n * (n - 1)) / 2;
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
        read_n(begin(a), n);
        sort(all(a));

        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int j = distance(begin(a), lower_bound(all(a), a[i] - 2));
            ans += C2(i - j);
        }
        cout << ans << endl;
    }
    return 0;
}
