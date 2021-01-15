/** @file
 * @date                2021-01-11
 * @url                 https://codeforces.com/contest/1401/problem/D
 * @tags                greedy, dfs, dp, implementation, sorting, trees
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           yes
 * @reading_time        2
 * @thinking_time       30
 * @coding_time         60
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Let `cnt(u, v)`, be the number of paths that cross edge $(u, v)$. The idea is
 * to assign the largest primes to the edges with largest `cnt`.
 *
 * Implementation details are described in
 * [Editorial](https://codeforces.com/blog/entry/81700). But the key idea is
 * that if $m < n - 1$, we fill the remaining with $1$s and otherwise we merge
 * the biggest primes into one.
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
using ll    = long long;
using ii    = pair<int, int>;
using vi    = vector<int>;
using Graph = vector<vi>;

struct DFS
{
    const Graph &g;

    function<void(int)>      fu0, fu1;
    function<void(int, int)> fuv0, fuv1;

    DFS(const Graph &g) : g(g) { reset(); }
    void traverse(int u, int p = -1)
    {
        fu0(u);
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            fuv0(u, v);
            traverse(v, u);
            fuv1(u, v);
        }
        fu1(u);
    }
    void operator()(int u, int p = -1) { traverse(u, p); }
    void reset()
    {
        fu0 = fu1 = [](int u) { (void)u; };
        fuv0 = fuv1 = [](int u, int v) { (void)u, (void)v; };
    }
};

vector<ll> get_edge_counts(const Graph &g)
{
    int        n = isz(g);
    vector<ll> ans(n, 0), sz(n, 1);

    DFS dfs(g);
    dfs.fuv1 = [&sz](int u, int v) { sz[u] += sz[v]; };
    dfs.fu1  = [&sz, &ans, n](int u) { ans[u] = (n - sz[u]) * sz[u]; };
    dfs(0);
    return ans;
}

int solve(const Graph &g, vector<ll> p)
{
    using mint = atcoder::modint1000000007;
    int  n = g.size(), m = p.size();
    auto cnt = get_edge_counts(g);

    swap(cnt.front(), cnt.back()), cnt.pop_back();
    sort(all(cnt), greater<ll>());
    sort(all(p), greater<ll>());

    if (m <= n - 1)
        p.resize(n - 1, 1);
    else // m > n - 1
    {
        auto end = begin(p) + m - n + 1;
        p[m - n + 1] *=
            accumulate(begin(p), end, mint(1), multiplies<mint>()).val();
        p.erase(begin(p), end);
    }

    mint ans = 0;

    for (int i = 0; i < n - 1; ++i)
        ans += mint(p[i]) * cnt[i];

    return ans.val();
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

        Graph g(n);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v, u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int m;
        cin >> m;
        vector<ll> p(m);
        for (auto &pi : p)
            cin >> pi;

        cout << solve(g, p) << endl;
    }
    return 0;
}
