#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

int const NMAX = 2e5 + 11;

int        n, m, d[NMAX], ans[NMAX], vis[NMAX];
vector<ii> g[NMAX];
ii         edges[NMAX];

void dfs(int u)
{
    vis[u] = true;
    for (auto [v, w] : g[u])
    {
        if (vis[v])
            continue;
        ans[v] = ans[u] + w;
        dfs(v);
    }
}

bool solve(void)
{
    for (int u = 0; u < n; u++)
        if (not vis[u])
            dfs(u);

    for (int i = 0; i < m; i++)
    {
        auto [u, v] = edges[i];
        if (ans[v] - ans[u] != d[i])
            return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v >> d[i], u--, v--;
        edges[i] = {u, v};
        g[u].emplace_back(v, d[i]);
        g[v].emplace_back(u, -d[i]);
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
