/** @file
 * @date                2020-12-06
 * @url                 https://codeforces.com/contest/1450/problem/B
 * @tags                brute_force, observation
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        2
 * @thinking_time       11
 * @coding_time         4
 * @time_complexity     O(n^2)
 * @memory_complexity   O(n)
 * @idea
 * Assume that optimally all points will merge into the point $c$ at coordinates
 * $(x_c, y_c)$.
 *
 * The key observation is that if such point exists, then all other points must
 * be at distance $\leq k$ from it, let's call such points *reachable* from $c$.
 *
 * To prove this (informally), assume otherwise: that there's a point
 * $d=(x_d,y_d)$ that is not reachable from $c$.
 *
 * If $d$ is not reachable by any point, then the answer is clearly $-1$.
 *
 * Let's say that there's a point $e$ that is reachable from both $c$ and $d$.
 *
 * We can do 3 operations:
 * 1. Merge with $c$ as center. Answer $ = -1$, because $d$ is not reachable.
 * 2. Merge with $d$ as center. The opposite as above.
 * 3. Merge with $e$ as center. If all points are reachable from $e$, then we
 * contradict our initial assumption and $e = c$. If there's at least a point
 * unreachable from $e$ then the answer is $-1$ by this same argument.
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

ll dist(ii a, ii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(vector<ii> &points, int k)
{
    for (auto a : points)
    {
        bool flag = true;
        for (auto b : points)
        {
            if (dist(a, b) > k)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return 1;
    }

    return -1;
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
        vector<ii> points(n);
        for (auto &[x, y] : points)
            cin >> x >> y;

        cout << solve(points, k) << endl;
    }
    return 0;
}
