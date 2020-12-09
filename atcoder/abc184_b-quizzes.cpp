/** @file
 * @date                2020-12-08
 * @url                 https://atcoder.jp/contests/abc184/tasks/abc184_b
 * @tags                easy, implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         2
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Iterate through all Takahashi's answers in order and update $x$ as the
 * problem says.
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

    int n, x;
    cin >> n >> x;

    while (n--)
    {
        char cur;
        cin >> cur;
        if (cur == 'o')
            x += 1;
        else
            x = max(0, x - 1);
    }
    cout << x << endl;

    return 0;
}
