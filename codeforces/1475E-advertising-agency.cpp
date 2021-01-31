/** @file
 * @date                2021-01-25
 * @url                 https://codeforces.com/contest/1475/problem/E
 * @tags                counting, sorting
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         10
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * [Comment](https://codeforces.com/blog/entry/87161?#comment-753182)
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = atcoder::modint1000000007;

ll C(int n, int k)
{
    mint up = 1, down = 1;
    for (int i = 0; i < k; ++i)
    {
        up *= n - i;
        down *= k - i;
    }
    return (up / down).val();
}

ll solve(vi a, int k)
{
    map<int, int, greater<int>> freq;

    for (auto ai : a)
        freq[ai]++;

    for (auto [x, cnt] : freq)
    {
        if (cnt < k)
            k -= cnt;
        else
            return C(cnt, k);
    }
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (auto &ai : a)
            cin >> ai;

        cout << solve(a, k) << endl;
    }
    return 0;
}
