---
layout: post
title: 52C Circular Rmq
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
const int NMAX = 2e5 + 11;
const int INF = 1e18 + 11;
ll n, a[NMAX], seg[4 * NMAX], lazy[4 * NMAX];
void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
        seg[v] = a[tl];
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        seg[v] = min(seg[2 * v], seg[2 * v + 1]);
    }
}
void lazy_propagate(ll v, ll tl, ll tr, ll val)
{
    seg[v] += val;
    if (tl != tr)
    {
        lazy[2 * v] += val;
        lazy[2 * v + 1] += val;
    }
    lazy[v] = 0;
}
void update(ll v, ll tl, ll tr, ll ql, ll qr, ll delta)
{
    if (lazy[v] != 0)
        lazy_propagate(v, tl, tr, lazy[v]);
    if (ql > qr)
        return;
    else if (tl == ql and tr == qr)
        lazy_propagate(v, tl, tr, delta);
    else
    {
        ll tm = (tl + tr) / 2;
        update(2 * v, tl, tm, ql, min(tm, qr), delta);
        update(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr, delta);
        seg[v] = min(seg[2 * v], seg[2 * v + 1]);
    }
}
ll query(ll v, ll tl, ll tr, ll ql, ll qr)
{
    if (lazy[v] != 0)
        lazy_propagate(v, tl, tr, lazy[v]);
    if (ql > qr)
        return INF;
    else if (tl == ql and tr == qr)
        return seg[v];
    else
    {
        ll tm = (tl + tr) / 2;
        return min(query(2 * v, tl, tm, ql, min(tm, qr)),
                   query(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr));
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q, l, r, delta;
    cin >> n;
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    build(a, 1, 0, n - 1);
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        if (cin.peek() != '\n')
        {
            cin >> delta;
            if (l > r)
            {
                update(1, 0, n - 1, l, n - 1, delta);
                update(1, 0, n - 1, 0, r, delta);
            }
            else
                update(1, 0, n - 1, l, r, delta);
        }
        else
        {
            if (l > r)
                cout << min(query(1, 0, n - 1, l, n - 1),
                            query(1, 0, n - 1, 0, r))
                     << endl;
            else
                cout << query(1, 0, n - 1, l, r) << endl;
        }
    }
    return 0;
}

{% endraw %}
```
