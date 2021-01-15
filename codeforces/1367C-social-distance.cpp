/** @file
 * @date                2021-01-13
 * @url                 https://codeforces.com/contest/1367/problem/C
 * @tags                greedy, implementation
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       4
 * @coding_time         20
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * For each block of consecutive zeros (with one on both ends) of size $m$,
 * one can place $ceil(\frac{m - 2k}{k + 1})$ ones.
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

int ceil(int a, int b) { return (a + b - 1) / b; }

int solve(string s, int k)
{
    s = "1" + string(k, '0') + s + string(k, '0') + "1";

    int cnt = 0;
    vi  lengths;
    for (auto c : s)
    {
        if (c == '0')
            ++cnt;
        else
        {
            lengths.push_back(max(cnt - 2 * k, 0));
            cnt = 0;
        }
    }

    return accumulate(all(lengths), 0LL, [k](int acc, int x) {
        return acc + ceil(x, k + 1);
    });
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int    n, k;
        string s;
        cin >> n >> k >> s;
        cout << solve(s, k) << endl;
    }
    return 0;
}
