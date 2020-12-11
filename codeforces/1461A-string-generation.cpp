/** @file
 * @date                2020-12-11
 * @url                 https://codeforces.com/contest/1461/problem/A
 * @tags                easy, constructive, greedy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       2
 * @coding_time         3
 * @time_complexity     O(n)
 * @memory_complexity   O(1)
 * @idea
 * Stacking "abc" together, will have the following property: No character will
 * have neighbors that are equal to each other or to itself.
 *
 * All palindromes need at least its center to be this way, so constructing one
 * is impossible.
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
        int n, k;
        cin >> n >> k;

        string ch = "abc";
        for (int i = 0; i < n; ++i)
            cout << ch[i % 3];
        cout << endl;
    }
    return 0;
}
