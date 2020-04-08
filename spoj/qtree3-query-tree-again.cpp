#include <climits>
#include <cstring>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using pii  = pair<int, int>;
using vi   = vector<int>;
using spii = set<pii>;

const int NMAX  = 1e5 + 11;
pii       EMPTY = make_pair(INT_MAX, -2);

int  n, cur_time = 0;
int  sz[NMAX], depth[NMAX], visit_time[NMAX];
bool black[NMAX];
vi   tree[NMAX];
spii seg[4 * NMAX];

// Key idea:
//   - When you update a node, all its subtree gets affected
//   - The segment trees stores on each node a set of identifiers for the black
//   nodes *above all* the vertices that involve that range in a flatten version
//   of the original tree
//   - For each node x on pos i, their affected subtree is  [i, i + sz(x) - 1]
//   - [i, i + sz(x) - 1] may split on the segment tree and match perfectly with
//   several nodes, so x may be inserted or removed from the segment tree
//   - To represent the path from the starting node to v, one should consider
//   the path from the root of the segtree to the leaf that represents x in
//   conjunction, because by definition all those nodes involve necessarily all
//   the nodes that their ranges represent, one of them being x.
//

void add_edge(int u, int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

void visit(int u, int d)
{
    depth[u]      = d;
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
        int  tm = (tl + tr) / 2;
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
