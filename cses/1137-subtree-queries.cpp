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

int const NMAX = 2e5 + 11;

int n, timer, val[NMAX], idval[NMAX], id[NMAX], sz[NMAX];
ll  t[4 * NMAX];
vi  g[NMAX];

void precompute(int u, int p)
{
    id[u]        = timer++;
    sz[u]        = 1;
    idval[id[u]] = val[u];
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        precompute(v, u);
        sz[u] += sz[v];
    }
}

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

ll sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl and r == tr)
        return t[v];
    int tm = (tl + tr) / 2;

    // min(r, tm), when we split we only care about the left part, but if the
    // range exceeds the queried range, then the remaining is unnecessary, so
    // pick r.
    return sum(v * 2, tl, tm, l, min(r, tm)) +
           sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        t[v] = new_val;
    else
    {
        int tm = (tl + tr) / 2;

        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int q;
    cin >> n >> q;

    read_n(val, n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    precompute(0, 0);
    build(idval, 1, 0, n - 1);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int u, x;
            cin >> u >> x, u--;
            update(1, 0, n - 1, id[u], x);
        }
        else
        {
            int u;
            cin >> u, u--;
            cout << sum(1, 0, n - 1, id[u], id[u] + sz[u] - 1) << endl;
        }
    }

    return 0;
}
