/** @file
 * @date                2021-01-04
 * @url                 https://codeforces.com/contest/1472/problem/B
 * @tags                math
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * First, if the total sum is not even, then it's impossible. Assume otherwise.
 * Second, if we have an even amonut of $2$'s (we'll necesarily have an even
 * number of $1$s) we can split it into two equal groups with the same sum.
 * Otherwise, we need at least a pair of $1$'s to fill the missing $2$.
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

bool solve(vi a)
{
    int sum = accumulate(all(a), 0), n = isz(a);
    int ones = count_if(all(a), [](int x) { return x == 1; });
    int twos = n - ones;

    return sum % 2 == 0 and ((twos % 2 == 0) or (ones > 0));
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
        for (auto &ai : a)
            cin >> ai;
        cout << (solve(a) ? "YES" : "NO") << endl;
    }
    return 0;
}
