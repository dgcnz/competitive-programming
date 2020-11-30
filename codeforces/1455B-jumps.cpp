/** @file
 * @date                2020-11-30
 * @url                 https://codeforces.com/contest/1455/problem/B
 * @tags                math, binary_search
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        2
 * @thinking_time       60
 * @coding_time         10
 * @time_complexity     O(\log{n})
 * @memory_complexity   O(1)
 * @idea
 * Note that we have to make at least $n$ jumps to reach $x$ (always jumping
 * forward), where $n$ is:
 *
 * $$ n = argmin_n(f(n)- x >= 0) $$
 *
 * Where $f(n) = \frac{n \times (n + 1)}{2}$. Intuitively, the answer shouldn't
 * be much bigger than that.
 *
 * Furthermore, we know that $0 <= f(n) - x < n$ (because of the $argmin$
 * constraints). We have to select a subset of our forward steps and turn them
 * into backward steps, or try increasing $n$.
 *
 * We can think of reversing a step $k$ as decreasing $f(n)$ by $k + 1$. For our
 * range of $[1, n]$, we would have options $[2, n + 1]$.
 *
 * The problem splits in three cases:
 * 1. $f(n) - x = 0$: $n$ is the answer.
 * 2. $2 <= f(n) - x < n$: We can reverse the step $f(n) - x - 1$. $n$ is the
 * answer.
 * 3. $f(n) - x = 1$: There's no way to reverse any step from $[1, n]$ to get to
 * $x$, but we can just take the $n + 1$ step backward. $n + 1$ is the answer.
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll        = long long;
using ii        = pair<int, int>;
using vi        = vector<int>;
using predicate = function<bool(ll)>;

inline ll f(ll n) { return (n * (n + 1)) / 2; }

ll bs(ll l, ll r, predicate p)
{
    // 0 0 0 0 0 1
    while (l < r)
    {
        ll m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        ll x;
        cin >> x;

        auto ok = [x](ll n) { return f(n) >= x; };

        int n = bs(1, x, ok);
        // dbg(x, n, f(n), f(n) - x);
        if (f(n) - x == 1)
            cout << n + 1 << endl;
        else
            cout << n << endl;
    }
    return 0;
}
