/** @file
 * @date                2020-12-05
 * @url                 https://atcoder.jp/contests/abc130/tasks/abc130_d
 * @tags                two_pointers
 * @status              AC
 * @score               3
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         40
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * We want to count the ranges $l, r$ inclusive whose sum is $\geq k$.
 *
 * For a fixed $r$, we need to count how many $l$'s satisfy this previous
 * condition. We note that as we increase $l$ for any fixed $r$, its sum
 * decreases and there's a point where it becomes $\leq k$.
 *
 * We can find this point using binary search. However, we may also note that we
 * can take advantage of the answer for a particular $r$, say $l_r$, to reduce
 * the search space of $r + 1$. Therefore, a two pointers approach can be
 * applied.
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
    int n;
    ll  k;
    cin >> n >> k;

    vector<ll> a(n), pa(n);

    read_n(begin(a), n);
    partial_sum(all(a), begin(pa));

    function<ll(int, int)> sum = [&pa](int l, int r) {
        return pa[r] - (l == 0 ? 0LL : pa[l - 1]);
    };

    ll ans = 0;
    for (int r = 0, l = 0; r < n; ++r)
    {
        // yes yes  false // stay at first false
        while (sum(l, r) >= k)
            ++l;
        ans += l;
    }
    cout << ans << endl;

    return 0;
}
