/** @file
 * @date                2020-12-12
 * @url                 https://atcoder.jp/contests/abc176/tasks/abc176_c
 * @tags                implementation, greedy
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         4
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Define new array $B$ such that it's elements are defined the following way:
 *
 * Base case $i = 1$:
 * $$b_1 = a_1$$
 *
 * For $1 < i \leq n$:
 *
 * $$b_i = max(b_{i - 1}, a_i)$$
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

ll solve(vector<ll> a)
{
    ll ans = 0, prev = a[0];
    for (auto &ai : a)
    {
        if (ai < prev)
        {
            ans += (prev - ai);
            ai = prev;
        }
        prev = ai;
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;

    cin >> n;
    vector<ll> a(n);
    read_n(begin(a), n);
    cout << solve(a) << endl;
    return 0;
}
