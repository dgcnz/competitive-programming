#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
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

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 1e3 + 11;

int n, m, visited[NMAX];
vi  g[NMAX];

bool cycle_exists(int u, int p)
{
    visited[u] = true;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        if (visited[v] or cycle_exists(v, u))
            return true;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        bool ans = 0;
        for (int i = 0; i < n; ++i)
        {
            g[i].clear();
            visited[i] = false;
        }

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for (int u = 0; u < n; ++u)
        {
            if (not ans and not visited[u] and cycle_exists(u, -1))
            {
                ans = 1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
