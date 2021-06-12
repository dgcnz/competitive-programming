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

string solve(string s)
{
    if (s.size() == 1)
        return "bacdefghijklmnopqrstuvwxyz";

    vector<set<int>> g(26);
    vector<int>      deg(26, 0);
    vector<bool>     vis(26, 0);
    int              n = s.size();
    for (int i = 1; i < n; ++i)
    {
        char u = s[i] - 'a', v = s[i - 1] - 'a';
        g[u].emplace(v);
        g[v].emplace(u);
        vis[u] = vis[v] = true;
    }

    if (any_of(all(g), [](set<int> &adj) { return adj.size() > 2; }))
        return "";

    string ans;
    for (int u = 0; u < 26; ++u)
        if (not vis[u])
            ans.push_back(char('a' + u));

    int u = 0;
    while (u < 26)
    {
        if (g[u].size() == 1)
            break;
        ++u;
    }
    if (u == 26)
        return "";

    int k = 26 - (int)ans.size();
    while (k--)
    {
        ans.push_back(char(u + 'a'));
        vis[u] = false;
        for (auto v : g[u])
        {
            if (vis[v])
            {
                u = v;
                break;
            }
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (auto ans = solve(s); ans.size())
        {
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
