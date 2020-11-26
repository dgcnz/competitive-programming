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

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

struct segment_tree
{
    int n;
    vi  t;
    segment_tree(vi const &a)
    {
        n = isz(a);
        t.resize(4 * n);
        build(a, 1, 0, n - 1);
    }
    inline int left(int v) { return 2 * v; }
    inline int right(int v) { return 2 * v + 1; }
    int        merge(int a, int b) { return gcd(a, b); }

    void build(vi const &a, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            int tm = (tl + tr) / 2;
            build(a, left(v), tl, tm);
            build(a, right(v), tm + 1, tr);
            t[v] = merge(t[left(v)], t[right(v)]);
        }
    }
    int query(int ql, int qr) { return query_util(1, 0, n - 1, ql, qr); }

    int query_util(int v, int tl, int tr, int ql, int qr)
    {
        if (ql == tl and qr == tr)
            return t[v];
        else if (ql > qr)
            return 0;
        else
        {
            int tm = (tl + tr) / 2;
            return merge(query_util(left(v), tl, tm, ql, min(tm, qr)),
                         query_util(right(v), tm + 1, tr, max(ql, tm + 1), qr));
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi a(n);
    read_n(a.begin(), n);

    segment_tree seg(a);

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int l = 0, r = 0;
        if (i > 0)
            l = seg.query(0, i - 1);
        if (i < n - 1)
            r = seg.query(i + 1, n - 1);
        ans = max(ans, gcd(r, l));
    }
    cout << ans << endl;

    return 0;
}
