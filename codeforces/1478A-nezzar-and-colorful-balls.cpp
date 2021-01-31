/** @file
 * @date                2021-01-28
 * @url                 https://codeforces.com/contest/1478/problem/A
 * @tags                greedy
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        0
 * @thinking_time       1
 * @coding_time         1
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Note that each subarray of equal value has to be painted with $x$ colors,
 * where $x$ is the size of such subarray. This is because otherwise, this would
 * yield a color sequence that is not strictly increasing.
 *
 * To find the minimum number of colors needed, we need to find the biggest
 * subarray of equal value.
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
        int n;
        cin >> n;
        vi freq(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            int ai;
            cin >> ai;
            freq[ai]++;
        }
        cout << *max_element(all(freq)) << endl;
    }
    return 0;
}
