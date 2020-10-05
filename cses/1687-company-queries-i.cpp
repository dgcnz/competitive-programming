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
int const LMAX = 20;
int const BITS = sizeof(int) * 8;

int n, timer, tin[NMAX], tout[NMAX], up[NMAX][LMAX];
vi  g[NMAX];

void dfs(int u, int p)
{
    tin[u]   = ++timer;
    up[u][0] = p;
    for (int i = 1; i < LMAX; ++i)
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (int v : g[u])
        if (v != p)
            dfs(v, u);

    tout[u] = ++timer;
}

int ancestor(int u, int k)
{
    int i;
    while (k)
    {
        i = BITS - __builtin_clz(k) - 1;
        u = up[u][i];
        k ^= 1LL << i;
    }
    if (u == 0)
        return -1;
    return u;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int q;
    cin >> n >> q;
    for (int i = 2; i <= n; ++i)
    {
        int ei;
        cin >> ei;
        g[ei].push_back(i);
        g[i].push_back(ei);
    }

    dfs(1, 0);
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        cout << ancestor(x, k) << endl;
    }
    return 0;
}
