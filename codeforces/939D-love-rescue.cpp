#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/graph>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int    n;
    string s1, s2;
    cin >> n;
    cin >> s1 >> s2;

    Graph<void> g(26);

    for (int i = 0; i < n; ++i)
        if (s1[i] != s2[i])
            g.add_edge(s1[i] - 'a', s2[i] - 'a'),
                g.add_edge(s2[i] - 'a', s1[i] - 'a');

    vector<bool>        vis(26, false);
    vector<ii>          ans;
    function<void(int)> dfs = [&](int u)
    {
        vis[u] = true;
        for (auto v : g[u])
            if (!vis[v])
                ans.emplace_back(u, v), dfs(v);
    };

    for (int u = 0; u < 26; ++u)
        if (!vis[u])
            dfs(u);

    cout << ans.size() << endl;

    for (auto [u, v] : ans)
        cout << char(u + 'a') << " " << char(v + 'a') << endl;

    return 0;
}
