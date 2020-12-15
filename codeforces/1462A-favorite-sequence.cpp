/** @file
 * @date                2020-12-15
 * @url                 https://codeforces.com/contest/1462/problem/A
 * @tags                easy, implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         3
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Reverse the operation.
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
    while (t--)
    {
        int n;
        cin >> n;

        vi a(n), ans(n);
        read_n(begin(a), n);

        int i = 0, l = 0, r = n - 1;
        while (l < r)
        {
            ans[i++] = a[l++];
            ans[i++] = a[r--];
        }
        if (l == r)
            ans[i] = a[l];
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
