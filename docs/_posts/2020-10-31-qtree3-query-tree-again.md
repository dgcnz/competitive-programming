---
layout: post
mathjax: true
title: qtree3 - Query Tree Again
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
using pii = pair<int, int>;
using vi = vector<int>;
using spii = set<pii>;
const int NMAX = 1e5 + 11;
pii EMPTY = make_pair(INT_MAX, -2);
int n, cur_time = 0;
int sz[NMAX], depth[NMAX], visit_time[NMAX];
bool black[NMAX];
vi tree[NMAX];
spii seg[4 * NMAX];
void add_edge(int u, int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}
void visit(int u, int d)
{
    depth[u] = d;
    visit_time[u] = cur_time;
}
void traverse(int u, int d)
{
    int local_time = cur_time;
    visit(u, d);
    for (int v : tree[u])
    {
        if (visit_time[v] == -1)
            traverse(v, d + 1);
    }
    sz[u] = cur_time - local_time;
}
void build(int v, int tl, int tr)
{
    if (tl == tr)
        seg[v] = {EMPTY};
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        seg[v] = {EMPTY};
    }
}
pii query(int v, int tl, int tr, int x)
{
    int pos = visit_time[x];
    if (tl == tr and pos == tl)
        return *seg[v].begin();
    else if (tl <= pos and pos <= tr)
    {
        int tm = (tl + tr) / 2;
        spii acc_ans;
        acc_ans.insert(*seg[v].begin());
        acc_ans.insert(query(v * 2, tl, tm, x));
        acc_ans.insert(query(v * 2 + 1, tm + 1, tr, x));
        return *acc_ans.begin();
    }
    else
        return EMPTY;
}
void update(int v, int tl, int tr, int ql, int qr, int x)
{
    if (ql > qr)
        return;
    if (tl == ql and tr == qr)
    {
        if (not black[x])
            seg[v].insert({depth[x], x});
        else
            seg[v].erase({depth[x], x});
    }
    else
    {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, ql, min(qr, tm), x);
        update(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr, x);
    }
}
int main(void)
{
    int q, u, v, type;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        add_edge(u - 1, v - 1);
    }
    memset(visit_time, -1, NMAX);
    traverse(0, 0);
    build(1, 0, n - 1);
    while (q--)
    {
        cin >> type >> v;
        v -= 1;
        if (type == 1)
            cout << query(1, 0, n - 1, v).second + 1 << endl;
        else
        {
            update(1, 0, n - 1, visit_time[v], visit_time[v] + sz[v] - 1, v);
            black[v] = !black[v];
        }
    }
    return 0;
}

{% endraw %}
```
</details>

