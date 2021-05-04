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

vi solve(vector<vi> g, vi c)
{
    vector<int>              vis(*max_element(all(c)) + 2, 0);
    vector<int>              ans = {0};
    function<void(int, int)> dfs = [&](int u, int p) {
        vis[c[u]]++;
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            if (vis[c[v]] == 0)
                ans.push_back(v);
            dfs(v, u);
        }
        vis[c[u]]--;
    };
    dfs(0, 0);
    sort(all(ans));
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi c(n);
    read(all(c));
    vector<vi> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto ans = solve(g, c);
    for (auto x : ans)
        cout << x + 1 << endl;
    return 0;
}
