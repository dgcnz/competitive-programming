/** @file
 * @date                2020-12-13
 * @url                 https://atcoder.jp/contests/abc185/tasks/abc185_a
 * @tags                easy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         1
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * The answer is the minimum of $a_1$, $a_2$, $a_3$ and $a_4$.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    array<int, 4> a;
    read_n(begin(a), 4);

    cout << *min_element(all(a)) << endl;

    return 0;
}
