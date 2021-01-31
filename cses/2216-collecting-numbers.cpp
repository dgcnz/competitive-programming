/** @file
 * @date                2021-01-19
 * @url                 https://cses.fi/problemset/task/2216
 * @tags                implementation
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Define a mapping (array), $id(a)$ that returns the position of the number
 * $a$ in the array $x$.
 *
 * The idea will be to use this mapping to know how many rounds we'll need to
 * visit all number in an increasing order.
 *
 * For example, if we start with number $a$ (initially $1$) we can see if  $a+1$
 * would be visited in the same round if $id(a + 1) > id(a)$.
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

int solve(vi a)
{
    int n = a.size();
    vi  id(n);

    for (int i = 0; i < n; ++i)
        id[a[i] - 1] = i;

    int cur = 0, ans = 0;
    while (cur < n)
    {
        ++cur;
        while (cur < n and id[cur] > id[cur - 1])
            ++cur;
        ++ans;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;

    cout << solve(a) << endl;
    return 0;
}
