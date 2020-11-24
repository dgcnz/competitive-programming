---
layout: post
mathjax: true
title: qtree - Query On Tree
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
using ll = long long;
using iii = tuple<int, int, int>;
using vi = vector<int>;
const int NMAX = 1e4 + 11;
int n, parent[NMAX], depth[NMAX], heavy[NMAX], head[NMAX], pos[NMAX], hldcnt;
int cost[NMAX];
vi g[NMAX];
iii edges[NMAX];
struct segtree
{
    int n;
    int t[4 * NMAX];
    segtree() {}
    segtree(int n) : n(n) {}
    void build(int a[]) { build_util(a, 1, 0, n - 1); }
    void build_util(int a[], int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = cost[tl];
        else
        {
            int tm = (tl + tr) >> 1;
            build_util(a, (v << 1), tl, tm);
            build_util(a, (v << 1) + 1, tm + 1, tr);
            t[v] = ((t[v << 1]) > (t[(v << 1) + 1]) ? (t[v << 1]) : (t[(v << 1) + 1]));
        }
    }
    int query(int ql, int qr) { return query_util(1, 0, n - 1, ql, qr); }
    int query_util(int v, int tl, int tr, int ql, int qr)
    {
        if (ql > qr)
            return 0;
        if (ql == tl and qr == tr)
            return t[v];
        int tm = (tl + tr) >> 1;
        int rl = query_util((v << 1), tl, tm, ql, min(tm, qr));
        int rr = query_util((v << 1) + 1, tm + 1, tr, max(tm + 1, ql), qr);
        return ((rl) > (rr) ? (rl) : (rr));
    }
    void update(int pos, int new_val)
    {
        update_util(1, 0, n - 1, pos, new_val);
    }
    void update_util(int v, int tl, int tr, int pos, int new_val)
    {
        if (tl > pos or tr < pos)
            return;
        if (tl == tr and tl == pos)
            t[v] = new_val;
        else
        {
            int tm = (tl + tr) >> 1;
            update_util(v << 1, tl, tm, pos, new_val);
            update_util((v << 1) + 1, tm + 1, tr, pos, new_val);
            t[v] = ((t[v << 1]) > (t[(v << 1) + 1]) ? (t[v << 1]) : (t[(v << 1) + 1]));
        }
    }
} st;
int dfs(int u)
{
    int usz = 1, mvz = 0, vsz;
    for (auto v : g[u])
    {
        if (v != parent[u])
        {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            vsz = dfs(v);
            usz += vsz;
            if (vsz > mvz)
            {
                mvz = vsz;
                heavy[u] = v;
            }
        }
    }
    return usz;
}
void decompose(int u, int h)
{
    head[u] = h;
    pos[u] = hldcnt++;
    if (heavy[u] != -1)
        decompose(heavy[u], h);
    for (auto v : g[u])
    {
        if (parent[u] != v and heavy[u] != v)
            decompose(v, v);
    }
}
void update(int i, int new_value)
{
    auto uvc = edges[i];
    int u = get<0>(uvc);
    int v = get<1>(uvc);
    if (depth[u] > depth[v])
        swap(u, v);
    st.update(pos[v], new_value);
}
int query(int u, int v)
{
    int ans = 0;
    while (head[u] != head[v])
    {
        if (depth[head[u]] > depth[head[v]])
            swap(u, v);
        ans = ((ans) > (st.query(pos[head[v]], pos[v])) ? (ans) : (st.query(pos[head[v]], pos[v])));
        v = parent[head[v]];
    }
    if (depth[u] > depth[v])
        swap(u, v);
    return ((ans) > (st.query(pos[u] + 1, pos[v])) ? (ans) : (st.query(pos[u] + 1, pos[v])));
}
void reset(void)
{
    hldcnt = 0;
    memset(heavy, -1, sizeof(*heavy) * n);
    for (int i = 0; i < n; ++i)
        g[i].clear();
}
int main(void)
{
    char s[10];
    int t, u, v, c, ei, nv;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        st = segtree(n);
        reset();
        for (int i = 0; i < n - 1; ++i)
        {
            scanf("%d %d %d", &u, &v, &c);
            edges[i] = make_tuple(u - 1, v - 1, c);
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        dfs(0);
        decompose(0, 0);
        for (int i = 0; i < n - 1; ++i)
        {
            auto uvc = edges[i];
            u = get<0>(uvc);
            v = get<1>(uvc);
            c = get<2>(uvc);
            if (depth[u] > depth[v])
                swap(u, v);
            cost[pos[v]] = c;
        }
        st.build(cost);
        while (scanf("%s", s) and s[0] != 'D')
        {
            if (s[0] == 'Q')
            {
                scanf("%d %d", &u, &v);
                printf("%d\n", query(u - 1, v - 1));
            }
            else
            {
                scanf("%d %d", &ei, &nv);
                update(ei - 1, nv);
            }
        }
    }
    return 0;
}

{% endraw %}
```
</details>

