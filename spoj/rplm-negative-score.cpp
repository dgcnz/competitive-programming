#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5 + 11;
const int INF  = 1e9 + 11;

int n, seg[4 * NMAX], a[NMAX];

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        seg[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;

        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);

        seg[v] = min(seg[2 * v], seg[2 * v + 1]);
    }
}

int query(int v, int tl, int tr, int ql, int qr)
{
    if (ql > qr)
        return INF;
    else if (ql == tl and qr == tr)
        return seg[v];
    else
    {
        int tm = (tl + tr) / 2;
        return min(query(2 * v, tl, tm, ql, min(tm, qr)),
                   query(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr));
    }
}

int main(void)
{
    int t, q, l, r;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc)
    {
        cin >> n >> q;
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        memset(seg, 0, sizeof(seg));
        build(a, 1, 0, n - 1);

        cout << "Scenario #" << tc << ":" << endl;
        while (q--)
        {
            cin >> l >> r;
            if (l > r)
                swap(l, r);
            cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
        }
    }

    return 0;
}
