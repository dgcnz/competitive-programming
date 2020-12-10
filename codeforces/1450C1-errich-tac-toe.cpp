/** @file
 * @date                2020-12-06
 * @url                 https://codeforces.com/contest/1450/problem/C1
 * @tags                constructive_algorithm, coloring_argument
 * @status              AC
 * @score               1
 * @difficulty          4
 * @editorial           yes
 * @reading_time        3
 * @thinking_time       90
 * @coding_time         15
 * @time_complexity     O(n^2)
 * @memory_complexity   O(n^2)
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/85348).
 * Hint: Use the Pigeonhole Principle to prove that:
 *
 * $$ \min{x_0, x_1, x_2} \leq floor(\frac{k}{3}) $$
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

void solve(vector<string> &board)
{
    int                  n = isz(board), k = 0;
    array<vector<ii>, 3> cnt;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 'X')
            {
                cnt[(i + j) % 3].emplace_back(i, j);
                ++k;
            }
        }
    }
    for (auto &v : cnt)
    {
        if (isz(v) <= k / 3)
        {
            for (auto [i, j] : v)
                board[i][j] = 'O';
            return;
        }
    }
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

        vector<string> board(n);
        read_n(begin(board), n);
        solve(board);
        write(all(board));
    }
    return 0;
}
