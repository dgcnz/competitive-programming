/** @file
 *
 * @title               [name]
 * @url                 [url]
 * @tags                [tag1], [tag2], ...
 *
 * @status              [AC/TLE/MLE]
 * @score               [0-5]
 * @difficulty          [0-5]
 * @editorial           [yes/no]
 *
 * @reading_time        [minutes]
 * @thinking_time       [minutes]
 * @coding_time         [minutes]
 * @debug_time          [minutes]
 *
 * @time_complexity     [O(f(n)))
 * @memory_complexity   [O(f(n))]
 * @idea
 *      [
 *      ...
 *      ]
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

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    return 0;
}
