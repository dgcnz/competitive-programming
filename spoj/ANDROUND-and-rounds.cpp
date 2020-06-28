#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2e5 + 11;

int n, a[NMAX], seg[4 * NMAX];

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        seg[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        seg[v] = seg[2 * v] & seg[2 * v + 1];
    }
}

int query(int v, int tl, int tr, int ql, int qr)
{
    if (ql > qr)
        return -1;
    if (ql == tl and qr == tr)
        return seg[v];
    else
    {
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, ql, min(tm, qr)) &
               query(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k, ans, l, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        memset(seg, 0, sizeof(seg));
        build(a, 1, 0, n - 1);

        for (int i = 0; i < n; ++i)
        {
            l = i - k;
            r = i + k;

            if (k >= n / 2)
                ans = query(1, 0, n - 1, 0, n - 1);
            else if (0 <= l and r < n) // fit
                ans = query(1, 0, n - 1, l, r);
            else
            {
                if (l < 0)
                {
                    ans = query(1, 0, n - 1, 0, r) &
                          query(1, 0, n - 1, n + l, n - 1);
                }
                if (r >= n)
                {
                    ans = query(1, 0, n - 1, l, n - 1) &
                          query(1, 0, n - 1, 0, r - n);
                }
            }

            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}
