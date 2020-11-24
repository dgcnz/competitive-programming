---
layout: post
mathjax: true
title: horrible - Horrible Queries
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
const int NMAX = 1e5 + 10;
using namespace std;
using ll = long long;
ll n, a[NMAX], seg[4 * NMAX], lazy[4 * NMAX];
void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
        seg[v] = a[tl];
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}
void lazy_propagate(ll v, ll tl, ll tr, ll val)
{
    seg[v] += (tr - tl + 1) * val;
    if (tl != tr)
    {
        lazy[2 * v] += val;
        lazy[2 * v + 1] += val;
    }
    lazy[v] = 0;
}
void update(ll v, ll tl, ll tr, ll ql, ll qr, ll x)
{
    if (lazy[v] != 0)
        lazy_propagate(v, tl, tr, lazy[v]);
    if (ql > qr)
        return;
    if (tl == ql and tr == qr)
        lazy_propagate(
            v, tl, tr, x);
    else
    {
        ll tm = (tl + tr) / 2;
        update(v * 2, tl, tm, ql, min(qr, tm), x);
        update(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr, x);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}
ll query(ll v, ll tl, ll tr, ll ql, ll qr)
{
    if (lazy[v] != 0)
        lazy_propagate(v, tl, tr, lazy[v]);
    if (ql > qr)
        return 0;
    if (tl == ql and tr == qr)
        return seg[v];
    else
    {
        ll tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, ql, min(qr, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr);
    }
}
int main(void)
{
    ll t, q, type, l, r, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        while (q--)
        {
            cin >> type >> l >> r;
            if (type)
                cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
            else
            {
                cin >> x;
                update(1, 0, n - 1, l - 1, r - 1, x);
            }
        }
        memset(seg, 0, 4 * NMAX * sizeof(ll));
        memset(lazy, 0, 4 * NMAX * sizeof(ll));
        memset(a, 0, n * sizeof(ll));
    }
    return 0;
}

{% endraw %}
```
</details>

