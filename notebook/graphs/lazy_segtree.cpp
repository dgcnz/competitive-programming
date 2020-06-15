#include <iostream>

const int NMAX = 1e6 + 10;

using namespace std;

int n, a[NMAX], seg[4 * NMAX], lazy[4 * NMAX];

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        seg[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}

// Computes current node and propagates change to lazy subtrees
void lazy_propagate(int v, int tl, int tr, int val)
{
    seg[v] += (tr - tl + 1) * val; // Apply changes
    if (tl != tr)                  // If non-leaf, propagate lazily to children
    {
        lazy[2 * v] += val;
        lazy[2 * v + 1] += val;
    }
    lazy[v] = 0; // Clear node
}

// [tl, tr] : tree's range
// [ql, qr] : query's range

void update(int v, int tl, int tr, int ql, int qr, int x)
{

    if (lazy[v] != 0) // Pending update. Propagate lazily on children.
        lazy_propagate(v, tl, tr, lazy[v]);

    if (ql > qr) // no overlap
        return;

    if (tl == ql and tr == qr) // complete overlap
        lazy_propagate(
            v, tl, tr, x); // Apply x to node, lazily propagate to children
    else                   // partial overlap
    {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, ql, min(qr, tm), x);
        update(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr, x);

        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}

int query(int v, int tl, int tr, int ql, int qr)
{
    if (lazy[v] != 0) // Pending update. Propagate on children.
        lazy_propagate(v, tl, tr, lazy[v]);

    if (ql > qr) // no overlap
        return 0;
    if (tl == ql and tr == qr) // complete overlap
        return seg[v];
    else // partial overlap
    {
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, ql, min(qr, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr);
    }
}
