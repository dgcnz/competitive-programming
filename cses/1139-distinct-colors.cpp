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

vector<int> solve(vector<vi> g, vector<int> c)
{
    int              n = g.size();
    vector<set<int>> distinct(n);
    vector<int>      ans(n);

    function<void(int, int)> dfs = [&](int u, int p)
    {
        distinct[u].insert(c[u]);
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            dfs(v, u);

            if (distinct[v].size() > distinct[u].size())
                swap(distinct[v], distinct[u]);
            distinct[u].insert(all(distinct[v]));
        }
        ans[u] = distinct[u].size();
    };

    dfs(0, 0);
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
    write(all(ans), " "), cout << endl;
    return 0;
}
