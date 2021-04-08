#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/math/combinatorics>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint998244353;

int const                NMAX = 2e5 + 11;
Combinations<NMAX, mint> C;

ll solve(vector<vi> g)
{
    int          n = g.size();
    vector<mint> ans(n, 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            ans[u] *= ans[v];
        }
        ans[u] *= C.fact[g[u].size()];
    };
    dfs(0, 0);
    return (n * ans[0]).val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<vi> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << solve(g) << endl;
    return 0;
}
