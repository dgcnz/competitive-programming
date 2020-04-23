#include <bits/stdc++.h>

using namespace std;
using vi   = vector<int>;
using ii   = pair<int, int>;
using iiii = tuple<int, int, int, int>;

const int NMAX = 1e5 + 11;

// @author: dgcnz
// @idea: hld + xor segtree + offline queries

struct segtree
{
    int n;
    vi  t;

    segtree(void) {}
    segtree(int n) : n(n) { t.resize(n << 2); }

    void build(int a[]) { build_util(a, 1, 0, n - 1); }
    void build_util(int a[], int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = {a[tl]};
        else
        {
            int tm = (tl + tr) >> 1;
            build_util(a, v << 1, tl, tm);
            build_util(a, (v << 1) + 1, tm + 1, tr);

            t[v] = t[v << 1] ^ t[(v << 1) + 1];
        }
    }
    int query(int ql, int qr, int val)
    {
        return query_util(1, 0, n - 1, ql, qr, val);
    }
    int query_util(int v, int tl, int tr, int ql, int qr, int val)
    {
        if (ql > qr)
            return 0;

        if (tl == ql and tr == qr)
            return t[v];

        int tm = (tl + tr) >> 1;

        return (query_util(v << 1, tl, tm, ql, min(qr, tm), val) ^
                query_util((v << 1) + 1, tm + 1, tr, max(ql, tm + 1), qr, val));
    }

    void update(int u, int val) { update_util(1, 0, n - 1, u, val); }

    void update_util(int v, int tl, int tr, int u, int val)
    {
        if (u < tl or tr < u)
            return;
        if (tl == tr and tl == u)
            t[v] = val;
        else
        {
            int tm = (tl + tr) >> 1;
            update_util(v << 1, tl, tm, u, val);
            update_util((v << 1) + 1, tm + 1, tr, u, val);
            t[v] = t[v << 1] ^ t[(v << 1) + 1];
        }
    }
} st;

int n, m, k;
int parent[NMAX], depth[NMAX], cost[NMAX];
int head[NMAX], heavy[NMAX], pos[NMAX], hldcnt;

vi   g[NMAX];
iiii edges[NMAX], queries[NMAX];
ii   qans[NMAX];

void reset(void)
{
    hldcnt = 0;
    memset(heavy, -1, sizeof(*heavy) * n);
    memset(cost, 0, sizeof(*cost) * n);
    for (int i = 0; i < n; ++i)
        g[i].clear();
}

int dfs(int u)
{
    int usz = 1, vsz, maxvsz = 0;

    for (auto v : g[u])
    {
        if (v == parent[u])
            continue;
        parent[v] = u;
        depth[v]  = depth[u] + 1;
        vsz       = dfs(v);
        usz += vsz;

        if (maxvsz < vsz)
        {
            heavy[u] = v;
            maxvsz   = vsz;
        }
    }

    return usz;
}

// u : node, h : head
void decompose(int u, int h)
{
    head[u] = h;
    pos[u]  = hldcnt++;

    if (heavy[u] != -1) // is not leaf
        decompose(heavy[u], h);

    for (auto v : g[u])
    {
        if (v != parent[u] and v != heavy[u])
            decompose(v, v);
    }
}

void update(iiii uvci)
{
    int u = get<0>(uvci);
    int v = get<1>(uvci);

    if (depth[u] > depth[v])
        swap(u, v);

    st.update(pos[v], get<2>(uvci));
}

int query(int u, int v, int k)
{
    int ans = 0;

    while (head[u] != head[v])
    {
        if (depth[head[u]] > depth[head[v]])
            swap(u, v);

        ans ^= st.query(pos[head[v]], pos[v], k);
        v = parent[head[v]];
    }

    if (depth[u] > depth[v])
        swap(u, v);

    return ans ^ st.query(pos[u] + 1, pos[v], k);
}

bool by_cost(iiii e1, iiii e2) { return get<2>(e1) < get<2>(e2); }

int main(void)
{
    int t, u, v, c, ei;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        st = segtree(n);
        reset();

        for (int i = 0; i < n - 1; ++i)
        {
            scanf("%d %d %d", &u, &v, &c);
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
            edges[i] = {u - 1, v - 1, c, i};
        }

        dfs(0);
        decompose(0, 0);

        scanf("%d", &m);

        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &u, &v, &k);
            queries[i] = {u - 1, v - 1, k, i};
        }

        sort(edges, edges + n - 1, by_cost);
        sort(queries, queries + m, by_cost);

        ei = 0;
        while (ei < (n - 1) and get<2>(edges[ei]) <= get<2>(queries[0]))
        {
            auto uvc = edges[ei++];
            u        = get<0>(uvc);
            v        = get<1>(uvc);

            if (depth[u] > depth[v])
                swap(u, v);

            cost[pos[v]] = get<2>(uvc);
        }

        st.build(cost);

        qans[0] = {
            get<3>(queries[0]),
            query(get<0>(queries[0]), get<1>(queries[0]), get<2>(queries[0]))};

        for (int qi = 1; qi < m; ++qi)
        {
            while (ei < (n - 1) and get<2>(edges[ei]) <= get<2>(queries[qi]))
                update(edges[ei++]);

            qans[qi] = {get<3>(queries[qi]),
                        query(get<0>(queries[qi]),
                              get<1>(queries[qi]),
                              get<2>(queries[qi]))};
        }

        sort(qans, qans + m); // sort by time

        for (int i = 0; i < m; ++i)
            printf("%d\n", qans[i].second);
    }
    return 0;
}
