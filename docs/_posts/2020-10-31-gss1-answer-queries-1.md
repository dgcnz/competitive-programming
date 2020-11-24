---
layout: post
mathjax: true
title: gss1 - Answer Queries 1
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
const int NMAX = 50000 + 11;
struct node
{
    int ls, rs, ss, ts;
};
int n;
int a[NMAX];
node t[4 * NMAX];
node make_node(int x)
{
    node ans;
    ans.ts = x;
    ans.ls = ans.rs = ans.ss = max(0, x);
    return ans;
}
node combine(node lc, node rc)
{
    int ls, rs, ss, ts;
    ls = max(lc.ls, lc.ts + rc.ls);
    rs = max(rc.rs, rc.ts + lc.rs);
    ss = max({lc.ss, rc.ss, lc.rs + rc.ls});
    ts = lc.ts + rc.ts;
    return {ls, rs, ss, ts};
}
void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = {a[tl], a[tl], a[tl], a[tl]};
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}
node query(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return make_node(0);
    if (l == tl and r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm)
        return query(v * 2, tl, tm, l, r);
    if (l > tm)
        return query(v * 2 + 1, tm + 1, tr, l, r);
    return combine(query(v * 2, tl, tm, l, tm),
                   query(v * 2 + 1, tm + 1, tr, tm + 1, r));
}
int main(void)
{
    int m, l, r;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    build(a, 1, 0, n - 1);
    cin >> m;
    while (m--)
    {
        cin >> l >> r;
        cout << query(1, 0, n - 1, l - 1, r - 1).ss << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

