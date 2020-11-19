/**
 * \addtogroup metadata
 * @{
 *
 * @title Filthy Rich Trees
 * @url https://codeforces.com/gym/102694/problem/E
 * @status AC
 * @score 9
 * @difficulty 8
 * @tags segment_tree, euler_tour_technique
 * @reading_time 5
 * @thinking_time 10
 * @coding_time 40
 * @idea Flattening tree with ETT. Build Segment Tree that stores the
 * multiplication of subtrees as log addition.
 * @time_complexity O(q*log(n))
 * @memory_complexity O(n)
 *
 * @}
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

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

template <typename T>
struct SegmentTree
{
    using vi = vector<int>;
    int       n;
    vector<T> t;

    SegmentTree(vi &a) : n(a.size())
    {
        t.resize(4 * n);
        build(a, 1, 0, n - 1);
    }
    void build(vi &a, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }

    inline T merge(T a, T b) { return a + b; }

    T query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
        if (l == tl and r == tr)
            return t[v];
        int tm = (tl + tr) / 2;

        // min(r, tm), when we split we only care about the left part, but if
        // the range exceeds the queried range, then the remaining is
        // unnecessary, so pick r.
        return merge(query(v * 2, tl, tm, l, min(r, tm)),
                     query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void update(int v, int tl, int tr, int pos, T new_val)
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
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
};

struct Tree
{
    using vi = vector<int>;

    int        n;
    vector<vi> g;

    Tree(int n) : n(n) { g.resize(n); }

    void add_edge(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int                      u,
             int                      p,
             function<void(int, int)> init,
             function<void(int, int)> din,
             function<void(int, int)> dout) const
    {
        init(u, p);
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            din(u, v);
            dfs(v, u, init, din, dout);
            dout(u, v);
        }
    }

    pair<vi, vi> flatten(void) const
    {
        int timer = 0;
        vi  sz(n, 1), vtime(n, 0);

        auto init = [&vtime, &timer](int u, int p) {
            (void)p;
            vtime[u] = timer++;
        };
        auto din  = [](int u, int v) { (void)u, (void)v; };
        auto dout = [&sz](int u, int v) { sz[u] += sz[v]; };

        dfs(0, -1, init, din, dout);
        return {vtime, sz};
    }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n;

    Tree tree(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, --u, --v;
        tree.add_edge(u, v);
    }

    auto [vtime, sz] = tree.flatten();

    vi                  a(n, log(1));
    SegmentTree<double> st(a);
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int u, new_val;
            cin >> u >> new_val, u--;
            st.update(1, 0, n - 1, vtime[u], log(new_val));
        }
        else
        {
            int u, v;
            cin >> u >> v, u--, v--;
            double ans = st.query(1, 0, n - 1, vtime[u], vtime[u] + sz[u] - 1) -
                         st.query(1, 0, n - 1, vtime[v], vtime[v] + sz[v] - 1);
            ans = max(log(1e-9), min(ans, log(1e9)));
            cout << fixed << setprecision(12) << exp(ans) << endl;
        }
    }
    return 0;
}
