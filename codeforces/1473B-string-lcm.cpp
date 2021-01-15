/** @file
 * @date                2021-01-14
 * @url                 https://codeforces.com/contest/1473/problem/B
 * @tags                implementation
 * @status              AC
 * @score               0
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       6
 * @coding_time         3
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Note that our lcm string, has to have size $lcm(a, b)$. Let's just extend
 * both $a$ and $b$ so that they have that size and then compare them.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size(), l = lcm(n, m);
        a.resize(l), b.resize(l);

        for (int i = n; i < l; ++i)
            a[i] = a[i % n];
        for (int i = m; i < l; ++i)
            b[i] = b[i % m];
        cout << (a == b ? a : "-1") << endl;
    }
    return 0;
}
