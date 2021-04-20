#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll kruskal(int n, vector<tuple<ll, int, int>> edges)
{
    ll  cost = 0;
    dsu DSU(n);
    sort(all(edges));
    for (auto [w, u, v] : edges)
    {
        if (DSU.leader(u) != DSU.leader(v))
        {
            cost += w;
            DSU.merge(u, v);
        }
    }
    return cost;
}

ll solve(ll p, vector<ll> a)
{
    int                         n = a.size();
    vector<pair<ll, int>>       sorted(n);
    vector<tuple<ll, int, int>> edges;
    for (int i = 0; i < n; ++i)
    {
        sorted.emplace_back(a[i], i);
        if (i > 0)
            edges.emplace_back(p, i - 1, i);
    }
    sort(all(sorted));
    vector<bool> vis(n);
    for (auto [w, i] : sorted)
    {
        if (w >= p)
            break;
        if (vis[i])
            continue;
        int l = i - 1, r = i + 1;
        while (l >= 0 and gcd(w, a[l]) == min(w, a[l]))
        {
            edges.emplace_back(w, i, l);
            vis[l--] = true;
        }
        while (r < n and gcd(w, a[r]) == min(w, a[r]))
        {
            edges.emplace_back(w, i, r);
            vis[r++] = true;
        }
    }
    return kruskal(n, edges);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll  p;
        cin >> n >> p;
        vector<ll> a(n);
        read(all(a));
        cout << solve(p, a) << endl;
    }
    return 0;
}
