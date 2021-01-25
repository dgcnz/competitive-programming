/** @file
 * @date                2021-01-25
 * @url                 https://codeforces.com/contest/1475/problem/D
 * @tags                binary_search, sortings
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       80
 * @coding_time         30
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * [Comment](https://codeforces.com/blog/entry/87161?#comment-753182)
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

int solve(vi a, vi b, int m)
{
    int        n = isz(a);
    vector<ll> acc[2];
    acc[0] = {0}, acc[1] = {0};

    for (int i = 0; i < n; ++i)
        acc[b[i] - 1].push_back(a[i]);

    for (int i = 0; i < 2; ++i)
    {
        auto start = begin(acc[i]) + 1;
        sort(start, end(acc[i]), greater<int>());
        partial_sum(start, end(acc[i]), start);
    }

    ll const INF = 1e15;
    ll       ans = INF;
    int      n1  = acc[0].size();
    for (int i = 0; i < n1; ++i)
    {
        auto it = lower_bound(all(acc[1]), max(0LL, m - acc[0][i]));
        if (it != acc[1].end())
        {
            int j = distance(begin(acc[1]), it);
            ans   = min(ans, i + 2LL * j);
        }
    }

    return ans == INF ? -1 : ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vi a(n), b(n);
        for (auto &ai : a)
            cin >> ai;

        for (auto &bi : b)
            cin >> bi;

        cout << solve(a, b, m) << endl;
    }
    return 0;
}
