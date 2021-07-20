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

int solve(vector<vi> g, vi a)
{
    int n = g.size();
    int k = count_if(all(g), [](auto &v) { return v.size() == 0; });

    vi dp(n, 1);

    function<void(int)> dfs = [&](int u)
    {
        if (g[u].size() == 0)
            return;

        dp[u] = a[u] ? 1e9 : 0;
        for (auto v : g[u])
        {
            dfs(v);
            if (a[u])
                dp[u] = min(dp[u], dp[v]);
            else
                dp[u] += dp[v];
        }
    };

    dfs(0);
    return k + 1 - dp[0];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi         a(n), p(n);
    vector<vi> g(n);
    read(all(a));

    for (int i = 1; i < n; ++i)
    {
        cin >> p[i], p[i]--;
        g[p[i]].push_back(i);
    }

    cout << solve(g, a) << endl;
    return 0;
}
