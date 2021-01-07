/** @file
 * @date                2020-12-20
 * @url                 https://codeforces.com/problemset/problem/1450/D
 * @tags                two_pointers, greedy, segment_tree, implementation
 * @status              AC
 * @score               3
 * @difficulty          4
 * @editorial           yes
 * @reading_time        2
 * @thinking_time       60
 * @coding_time         30
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/85348).
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int e() { return 0x7fffffff; }
int min(int a, int b) { return std::min(a, b); }

using RMQ = atcoder::segtree<int, min, e>;

vector<int> solve(vi a)
{
    int n = isz(a);
    vi  ans(n, 0), cnt(n, 0);
    RMQ rmq(a);

    for (auto ai : a)
        cnt[ai]++;

    ans[0]     = all_of(all(cnt), [](int x) { return x > 0; });
    ans[n - 1] = cnt[0] > 0;
    if (!ans[n - 1])
        return ans;

    int i = 0, l = 0, r = n - 1;
    for (; i < n - 1; ++i)
    {
        if (a[l] == i)
            l++;
        else if (a[r] == i)
            r--;
        else
            break;
        if (rmq.prod(l, r + 1) != i + 1)
            break;
    }
    for (int j = n - (i + 1); j < n - 1; ++j)
        ans[j] = true;
    return ans;
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
            cin >> ai, ai--;

        auto ans = solve(a);
        for (auto x : ans)
            cout << x;
        cout << endl;
    }
    return 0;
}
