#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<vi> g, vector<ll> l, vector<ll> r)
{
    int        n = g.size();
    vector<ll> dpl(n, 0), dpr(n, 0);

    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            dpl[u] += max(dpl[v] + abs(l[u] - l[v]), dpr[v] + abs(l[u] - r[v]));
            dpr[u] += max(dpl[v] + abs(r[u] - l[v]), dpr[v] + abs(r[u] - r[v]));
        }
    };

    dfs(0, 0);
    return max(dpl[0], dpr[0]);
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
        vector<vi> g(n);
        vector<ll> l(n), r(n);
        for (int i = 0; i < n; ++i)
            cin >> l[i] >> r[i];

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v, u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << solve(g, l, r) << endl;
    }
    return 0;
}
