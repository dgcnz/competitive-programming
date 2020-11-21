---
layout: post
mathjax: true
title: 1647 Range Minimum Queries I
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
ll INF = 1e17;
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
    ll merge(ll a, ll b) { return min(a, b); }
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
    auto query(int v, int tl, int tr, int ql, int qr)
    {
        if (tl == ql and tr == qr)
            return t[v];
        else if (ql > qr)
            return INF;
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
        int ql, qr;
        cin >> ql >> qr, ql--, qr--;
        cout << st.query(1, 0, n - 1, ql, qr) << endl;
    }
    return 0;
}

{% endraw %}
```
