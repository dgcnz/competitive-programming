#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;

vector<vector<ii>> solve(int n, vector<ii> pairs)
{
    vector<vi> g(n);
    for (auto [a, b] : pairs)
    {
        if (a > b)
            swap(a, b);
        g[a].push_back(b);
    }

    vector<vector<ii>> ans(n);
    for (int a = 0; a < n; ++a)
    {
        if (ans[a].empty())
            ans[a].emplace_back(n * a, a);
        for (auto b : g[a])
        {
            ans[a].emplace_back(n * b + a, a);
            ans[b].emplace_back(n * b + a, b);
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<ii> pairs(m);
    for (auto &[a, b] : pairs)
        cin >> a >> b, a--, b--;

    auto ans = solve(n, pairs);
    for (auto pos : ans)
    {
        cout << pos.size() << endl;
        for (auto [x, y] : pos)
            cout << x + 1 << " " << y + 1 << endl;
    }

    return 0;
}
