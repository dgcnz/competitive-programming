/** @file
 * @date                2020-11-29
 * @url                 https://codeforces.com/contest/1443/problem/A
 * @tags                math, greedy
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        2
 * @thinking_time       9
 * @coding_time         4
 * @time_complexity     O(n)
 * @memory_complexity   O(1)
 * @idea
 * (Disclaimer: I came with an uglier $O(n^2 \log{n})$ solution, but a good
 * friend of mine pointed out that I was doing unnecessary computation. Anyway,
 * this is the improved version.)
 *
 * First, note that the seats must be composite numbers that share a factor but
 * are not multiples of themselves.
 *
 * So, our answer has to be a subset of the  multiples of some prime in [1, 4n].
 *
 * Furthermore, note that one of the best candidates to fulfill this
 * common-factor role is 2, since there are more multiples of 2 than any other
 * prime in that range.
 *
 * Finally, note that it is always better to pick bigger numbers than smaller
 * numbers, because they are less likely to be multiples of each other.
 *
 * Our final answer is:
 *
 * $$2n + 2, 2n + 4, ... , 4n$$
 *
 * This subset of $n$ numbers have a common factor of 2 and are definitely not
 * multiples of each other, so we're good to go.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 2 * n + 2; i <= 4 * n; i += 2)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
