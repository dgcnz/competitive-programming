/** @file
 * @date                2020-12-30
 * @url                 https://codeforces.com/contest/1466/problem/D
 * @tags                greedy, trees
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       40
 * @coding_time         10
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Let's say we have $k$ colors to paint the tree. Note that it is always
 * optimal that there's only one connected component for each color painted.
 *
 * Painting a tree with $k$ colors with the above strategy means that some of
 * the vertices will be shared by several colored subgraphs, i.e, that $w_i$
 * (let's say node $i$ is shared $y$ times) will be counted $y$ times in the
 * answer.
 *
 * This suggest a greedy stretegy where we pick those nodes with highest $w$ to
 * be the intersections of our colored subgraphs, ie, those that will be counted
 * repeatedly.
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
using ll  = long long;
using ii  = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;

vector<ll> solve(vector<vi> &g, vector<ll> &w)
{
    int        n = isz(g);
    vector<ll> sorted, ps;
    for (int u = 0; u < n; ++u)
        for (int i = 0, m = isz(g[u]) - 1; i < m; ++i)
            sorted.push_back(w[u]);

    sort(all(sorted), greater<ll>());
    partial_sum(all(sorted), back_inserter(ps));

    ll sum = accumulate(all(w), 0LL);

    vector<ll> ans(n - 1, sum);
    for (int k = 2; k <= n - 1; ++k)
        ans[k - 1] += ps[k - 2];

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
        vector<ll> w(n);
        for (auto &x : w)
            cin >> x;

        vector<vi> g(n);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v, u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        auto ans = solve(g, w);

        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
