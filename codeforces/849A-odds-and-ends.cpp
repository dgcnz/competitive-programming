/** @file
 * @date                2021-01-02
 * @url                 https://codeforces.com/contest/849/problem/A
 * @tags                implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       6
 * @coding_time         2
 * @time_complexity     O(1)
 * @memory_complexity   O(n)
 * @idea
 * First of all, if $n$ is even then it is impossible to decompose it
 * into subsegments of odd sizes.
 *
 * Otherwise if $n$ is odd then there must be necessarily a subsegment
 * containing the first element and a subsegment containing the last element,
 * otherwise it is not possible. If true, we can take the entire array as a
 * valid subsegment.
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
    int n = isz(a);
    if ((a[0] % 2 != 1) or (a.back() % 2 != 1))
        return false;
    return n % 2;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;

    cout << (solve(a) ? "Yes" : "No") << endl;
    return 0;
}
