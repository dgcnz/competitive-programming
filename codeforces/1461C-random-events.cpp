/** @file
 * @date                2020-12-11
 * @url                 https://codeforces.com/contest/1461/problem/C
 * @tags                observation, probability
 * @status              AC
 * @score               0
 * @difficulty          3
 * @editorial           no
 * @reading_time        2
 * @thinking_time       20
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Key observation: we only care about the last position that is unsorted.
 *
 * The reasoning behind this is that the numbers that go after that are already
 * sorted and the numbers that come before will always have more or equal
 * probability of getting sorted.
 *
 * So, for such number $a_{last}$, the probability of staying unsorted is:
 *
 * $$ (1 - p_{i_0}) (1 - p_{i_0}) ... (1 - p_{i_k}) $$
 *
 * for all $i_j$'s such that $last \leq r_{i_j}$.
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vi a(n);
        read_n(begin(a), n);

        int last = n;
        while (last >= 1 and a[last - 1] == last)
            --last;

        double P_unsorted = (last == 0 ? 0.0 : 1.0);
        while (m--)
        {
            int    r;
            double p;
            cin >> r >> p;
            if (r >= last)
                P_unsorted *= (double(1) - p);
        }
        cout << setprecision(12) << fixed << double(1) - P_unsorted << endl;
    }
    return 0;
}
