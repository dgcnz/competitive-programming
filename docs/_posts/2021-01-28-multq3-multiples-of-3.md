---
layout: post
mathjax: true
title: multq3 - Multiples Of 3
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
using namespace std;
using iii = array<int, 3>;
const int NMAX = 1e5 + 11;
int n;
int lazy[4 * NMAX];
iii seg[4 * NMAX];
void lazy_propagate(int v, int tl, int tr, int delta)
{
    iii temp(seg[v]);
    int last = (0 - delta % 3 + 3) % 3;
    for (int i = 0; i < 3; ++i)
    {
        seg[v][i] = temp[last];
        last = (last + 1) % 3;
    }
    if (tl != tr)
    {
        lazy[2 * v] += delta;
        lazy[2 * v + 1] += delta;
    }
    lazy[v] = 0;
}
inline iii merge(iii a, iii b)
{
    return {a[0] + b[0], a[1] + b[1], a[2] + b[2]};
}
void update(int v, int tl, int tr, int ql, int qr, int delta)
{
    if (lazy[v] != 0)
        lazy_propagate(v, tl, tr, lazy[v]);
    if (ql > qr)
        return;
    if (ql == tl and qr == tr)
        lazy_propagate(v, tl, tr, delta);
    else
    {
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, ql, min(qr, tm), delta);
        update(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr, delta);
        seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
    }
}
iii query(int v, int tl, int tr, int ql, int qr)
{
    if (lazy[v] != 0)
        lazy_propagate(v, tl, tr, lazy[v]);
    if (ql > qr)
        return {0, 0, 0};
    if (ql == tl and qr == tr)
        return seg[v];
    else
    {
        int tm = (tl + tr) / 2;
        return merge(query(2 * v, tl, tm, ql, min(tm, qr)),
                     query(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr));
    }
}
void build(int v, int tl, int tr)
{
    if (tl == tr)
        seg[v] = {1, 0, 0};
    else
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
    }
}
int main(void)
{
    int q, type, ql, qr;
    cin >> n >> q;
    build(1, 0, n - 1);
    while (q--)
    {
        cin >> type >> ql >> qr;
        if (type == 0)
        {
            update(1, 0, n - 1, ql, qr, +1);
        }
        else
        {
            auto [r0, r1, r2] = query(1, 0, n - 1, ql, qr);
            cout << r0 << endl;
        }
    }
    return 0;
}

{% endraw %}
```
</details>

