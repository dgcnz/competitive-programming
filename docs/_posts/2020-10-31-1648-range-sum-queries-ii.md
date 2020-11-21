---
layout: post
title: 1648 Range Sum Queries Ii
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
struct segment_tree
{
    int n;
    vector<ll> t;
    segment_tree(vi const &a)
    {
        n = (int)a.size();
        t.resize(4 * (int)a.size());
        build(a, 1, 0, n - 1);
    }
    ll merge(ll a, ll b) { return a + b; }
    void build(vi const &a, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = merge(t[2 * v], t[2 * v + 1]);
        }
    }
    void update(int v, int tl, int tr, int ix, int new_val)
    {
        if (tl == tr and tl == ix)
            t[v] = new_val;
        else if (tl <= ix and ix <= tr)
        {
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, ix, new_val);
            update(2 * v + 1, tm + 1, tr, ix, new_val);
            t[v] = merge(t[2 * v], t[2 * v + 1]);
        }
    }
    auto query(int v, int tl, int tr, int ql, int qr)
    {
        if (tl == ql and tr == qr)
            return t[v];
        else if (ql > qr)
            return 0LL;
        else
        {
            int tm = (tl + tr) / 2;
            return merge(query(2 * v, tl, tm, ql, min(tm, qr)),
                         query(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr));
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
            int ix, new_val;
            cin >> ix >> new_val, ix--;
            st.update(1, 0, n - 1, ix, new_val);
        }
        else
        {
            int ql, qr;
            cin >> ql >> qr, ql--, qr--;
            cout << st.query(1, 0, n - 1, ql, qr) << endl;
        }
    }
    return 0;
}

```
