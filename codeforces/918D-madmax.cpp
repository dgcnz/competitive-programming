#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()

using namespace std;
using ii = pair<int, int>;

int const NMAX = 1e2 + 11;
int const CMAX = 26;

int        n, m;
bool       mem[NMAX][NMAX][CMAX], vis[NMAX][NMAX][CMAX];
vector<ii> g[NMAX];

bool dp(int u, int v, int c)
{
    auto &ans = mem[u][v][c];
    if (vis[u][v][c])
        return ans;
    else
    {
        vis[u][v][c] = true;
        return ans   = any_of(all(g[u]), [c, v](ii uc) {
                   auto [up, cp] = uc;
                   return cp >= c and not dp(v, up, cp);
               });
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int  u, v;
    char c;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> c, --u, --v, c -= 'a';
        g[u].emplace_back(v, (int)c);
    }

    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
            cout << (dp(u, v, 0) ? 'A' : 'B');
        cout << endl;
    }
    return 0;
}
