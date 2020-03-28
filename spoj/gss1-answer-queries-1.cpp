#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

const int NMAX = 50000 + 11;

struct node
{
    int ls, rs, ss, ts;
};

int n;
int a[NMAX];

node t[4 * NMAX];

node make_node(int x) // check
{
    node ans;
    ans.ts = x;
    ans.ls = ans.rs = ans.ss = max(0, x);
    return ans;
}

node combine(node lc, node rc) // check
{
    int ls, rs, ss, ts;

    ls = max(lc.ls, lc.ts + rc.ls);
    rs = max(rc.rs, rc.ts + lc.rs);
    ss = max({lc.ss, rc.ss, lc.rs + rc.ls});
    ts = lc.ts + rc.ts;

    return {ls, rs, ss, ts};
}

void build(int a[], int v, int tl, int tr) // check
{
    if (tl == tr)
        t[v] = /* make_node(a[tl]);*/ {a[tl], a[tl], a[tl], a[tl]};
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
