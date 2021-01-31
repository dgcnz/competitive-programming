/** @file
 * @date                2021-01-28
 * @url                 https://codeforces.com/contest/1478/problem/B
 * @tags                observation, ad-hoc, brute_force
 * @status              AC
 * @score               2
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         10
 * @time_complexity     O(q \log{n})
 * @memory_complexity   O(1)
 * @idea
 *
 * For a given $d$, we can observe the following:
 * 1. Each number $x$, $x \geq 10d$ can be built by a combination of an element
 * in the range $10d, 10d + 9$ and zero or more $d$.
 * 2. Each number $x$, $x < 10d$ has the form: $10 k_1 + d k_2$.
 *
 * Using these two facts, we can can brute_force $x < 10d$ and answer right away
 * $x \geq 10d$.
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool test(int x, int d)
{
    for (int i = d; i <= x; i += d)
        if (x % 10 == i % 10)
            return true;
    while (x)
    {
        if (x % 10 == d)
            return true;
        x /= 10;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int q, d;
        cin >> q >> d;
        while (q--)
        {
            int x;
            cin >> x;
            if (x >= d * 10 or test(x, d))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
