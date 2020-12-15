/** @file
 * @date                2020-12-15
 * @url                 https://codeforces.com/contest/1462/problem/D
 * @tags                brute_force
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       40
 * @coding_time         7
 * @time_complexity     O(n^2)
 * @memory_complexity   O(n)
 * @idea
 * Let's say that $b$ is an array reachable from $a$ by applying the described
 * operation such that $b_i = x$ for all $1 \leq i leq k$, where $k \leq n$.
 * Note that $x$ is completely defined by $k$, so call it $x_k$:
 *
 * $$ x_k =  \frac{\sum_{i = 1}^{n} a_i}{k} $$
 *
 * The problem reduces to finding the biggest $k$ possible, and that can be
 * found by testing all possible $1 \leq k \leq n$ in descending order, and
 * returning the first match. Testing if $x_k$ is feasible can be done in a
 * simple $O(n)$ check.
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

bool test(const vi &a, ll x)
{
    int n   = isz(a);
    ll  cur = 0;
    for (int i = 0; i < n; ++i)
    {
        if (cur + a[i] < x)
            cur += a[i];
        else if (cur + a[i] > x)
            return false;
        else
            cur = 0;
    }
    return cur == 0;
}

int solve(const vi &a)
{
    int n   = isz(a);
    ll  sum = accumulate(all(a), 0LL);
    for (int i = n; i > 1; --i)
        if (sum % i == 0 and test(a, sum / i))
            return n - i;
    return n - 1;
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

        vi a(n);
        read_n(begin(a), n);

        cout << solve(a) << endl;
    }
    return 0;
}
