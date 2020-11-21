---
layout: post
mathjax: true
title: 1651 Range Update Queries
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
struct segment_tree
{
    int n;
    vector<ll> t, lazy;
    segment_tree(vi const &a)
    {
        n = (int)a.size();
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(a, 1, 0, n - 1);
    }
    void lazy_propagate(int v, int tl, int tr, ll val)
    {
        t[v] += (tr - tl + 1) * val;
        if (tl != tr)
        {
            lazy[2 * v] += val;
            lazy[2 * v + 1] += val;
        }
        lazy[v] = 0;
    }
    void build(vi const &a, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }
    void update(int v, int tl, int tr, int ql, int qr, int delta)
    {
        if (lazy[v] != 0)
            lazy_propagate(v, tl, tr, lazy[v]);
        if (ql > qr)
            return;
        if (tl == ql and tr == qr)
            lazy_propagate(v, tl, tr, delta);
        else
        {
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, ql, min(tm, qr), delta);
            update(v * 2 + 1, tm + 1, tr, max(tm + 1, ql), qr, delta);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }
    ll query(int v, int tl, int tr, int ql, int qr)
    {
        if (lazy[v] != 0)
            lazy_propagate(v, tl, tr, lazy[v]);
        if (ql > qr)
            return 0;
        if (tl == ql and tr == qr)
            return t[v];
        else
        {
            int tm = (tl + tr) / 2;
            return query(2 * v, tl, tm, ql, min(tm, qr)) +
                   query(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr);
        }
    }
};
int main(void)
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;
    segment_tree st(a);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int ql, qr, delta;
            cin >> ql >> qr >> delta, ql--, qr--;
            st.update(1, 0, n - 1, ql, qr, delta);
        }
        else
        {
            int ix;
            cin >> ix, ix--;
            cout << st.query(1, 0, n - 1, ix, ix) << endl;
        }
    }
    return 0;
}

{% endraw %}
```
