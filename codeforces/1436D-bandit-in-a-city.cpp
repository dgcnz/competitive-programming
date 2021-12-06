#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct Data
{
    ll mx, rem, cnt;
};

ll iceil(ll a, ll b) { return (a + b - 1) / b; }

ll solve(vector<vi> g, vector<ll> a)
{
    function<Data(int)> dfs = [&](int u)
    {
        if (g[u].empty())
            return Data{a[u], 0, 1};

        Data         ans{0, 0, 0};
        vector<Data> x;
        for (auto v : g[u])
        {
            x.push_back(dfs(v));
            ans.mx = max(ans.mx, x.back().mx);
            ans.cnt += x.back().cnt;
        }
        for (auto [mx, rem, cnt] : x)
            ans.rem += rem + cnt * (ans.mx - mx);

        ll delta = min(a[u], ans.rem);
        a[u] -= delta;
        ans.rem -= delta;
        if (a[u])
        {
            ll filled = a[u] / ans.cnt;
            ans.mx += filled + bool(a[u] % ans.cnt);
            a[u] -= filled * ans.cnt;
            ans.rem = (ans.cnt - (a[u] % ans.cnt)) % ans.cnt;
        }
        return ans;
    };

    return dfs(0).mx;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<vi> g(n);
    for (int i = 1; i < n; ++i)
    {
        int x;
        cin >> x, x--;
        g[x].push_back(i);
    }
    vector<ll> a(n);
    read(all(a));

    auto ans = solve(g, a);
    cout << ans << endl;

    return 0;
}
