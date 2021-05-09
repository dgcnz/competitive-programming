#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint1000000007;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, l;
    cin >> n >> l;

    vector<vi> g(l);
    for (int i = 0; i < l; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int m;
            cin >> m, m--;
            g[i].push_back(m);
        }
    }

    set<int>            ans;
    vector<mint>        dp(l, 0);
    vector<bool>        vis(l, 0);
    function<mint(int)> dfs = [&](int u) {
        if (vis[u])
            return dp[u];
        vis[u] = true;
        for (auto v : g[u])
        {
            if (v >= l)
                ans.insert(v), dp[u]++;
            if (v < l)
                dp[u] += dfs(v);
        }
        return dp[u];
    };

    cout << dfs(0).val() << " " << ans.size() << endl;
    return 0;
}
