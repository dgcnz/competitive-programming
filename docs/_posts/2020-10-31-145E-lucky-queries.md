---
layout: post
mathjax: true
title: 145E Lucky Queries
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
struct node
{
    int n4, n7;
    int n47, n74;
};
const int NMAX = 1e6 + 11;
int n, a[NMAX];
bool lazy[4 * NMAX];
node seg[4 * NMAX];
node merge(node u, node v)
{
    node ans;
    ans.n4 = u.n4 + v.n4;
    ans.n7 = u.n7 + v.n7;
    ans.n47 = max({u.n4 + v.n47, u.n47 + v.n7});
    ans.n74 = max({u.n7 + v.n74, u.n74 + v.n4});
    return ans;
}
inline node make_leaf(int d) { return {(d == 4), (d == 7), 1, 1}; }
void lazy_propagate(int v, int tl, int tr)
{
    swap(seg[v].n4, seg[v].n7);
    swap(seg[v].n47, seg[v].n74);
    if (tl != tr)
    {
        lazy[2 * v] = !lazy[2 * v];
        lazy[2 * v + 1] = !lazy[2 * v + 1];
    }
    lazy[v] = !lazy[v];
}
void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        seg[v] = make_leaf(a[tl]);
    else
    {
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
    }
}
void update(int v, int tl, int tr, int ql, int qr)
{
    if (lazy[v])
        lazy_propagate(v, tl, tr);
    if (ql > qr)
        return;
    if (tl == ql and tr == qr)
    {
        lazy_propagate(v, tl, tr);
        lazy[v] = false;
    }
    else
    {
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, ql, min(tm, qr));
        update(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr);
        seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
    }
}
node query(int v, int tl, int tr, int ql, int qr)
{
    if (lazy[v])
        lazy_propagate(v, tl, tr);
    if (ql > qr)
        return {};
    if (tl == ql and tr == qr)
        return seg[v];
    else
    {
        int tm = (tl + tr) / 2;
        return merge(query(2 * v, tl, tm, ql, min(tm, qr)),
                     query(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr));
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, l, r;
    string s, type;
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < n; ++i)
        a[i] = s[i] - '0';
    build(a, 1, 0, n - 1);
    while (q--)
    {
        cin >> type;
        if (type == "count")
        {
            node ans = query(1, 0, n - 1, 0, n - 1);
            cout << ans.n47 << endl;
        }
        else
        {
            cin >> l >> r;
            update(1, 0, n - 1, l - 1, r - 1);
        }
    }
    return 0;
}

{% endraw %}
```