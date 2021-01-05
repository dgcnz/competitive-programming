/** @file
 * @date                2021-01-05
 * @url                 https://codeforces.com/contest/1471/problem/A
 * @tags                greedy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        0
 * @thinking_time       1
 * @coding_time         2
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * - Max: Leave the array as it is.
 * - Min: Merge the array into an element.
 *
 * Intuitively, by summing the entire array into an element, we reduce the
 * increasing effect of the ceil function.
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

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<ll> a(n);

        for (auto &ai : a)
            cin >> ai;

        ll min = ceil(accumulate(all(a), 0LL), x);

        ll max = 0;
        for (auto ai : a)
            max += ceil(ai, x);
        cout << min << " " << max << endl;
    }
    return 0;
}
