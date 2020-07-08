#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int NMAX = 1e5 + 11;

ll n, a[NMAX], seg[4 * NMAX];

void update(ll v, ll tl, ll tr, ll ql, ll qr);

void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
        seg[v] = a[tl];
    else
    {
        ll tm = (tl + tr) / 2;

        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);

        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}

void lazy_propagate(ll v, ll tl, ll tr)
{
    if (tr - tl + 1 < seg[v]) // otherwise all numbers in [tl, tr] are 1
    {
        if (tl == tr)
        {
            seg[v] = (ll)sqrt(seg[v]);
        }
        else
        {
            ll tm = (tl + tr) / 2;
            update(2 * v, tl, tm, tl, tm);
            update(2 * v + 1, tm + 1, tr, tm + 1, tr);
            seg[v] = seg[2 * v] + seg[2 * v + 1];
        }
    }
}

void update(ll v, ll tl, ll tr, ll ql, ll qr)
{
    if (ql > qr)
        return;
    if (tl == ql and tr == qr)
        lazy_propagate(v, tl, tr);
    else
    {
        ll tm = (tl + tr) / 2;
        update(2 * v, tl, tm, ql, min(tm, qr));
        update(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}

ll query(ll v, ll tl, ll tr, ll ql, ll qr)
{
    if (ql > qr)
        return 0;
    else if (tl == ql and tr == qr)
        return seg[v];
    else
    {
        ll tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, ql, min(tm, qr)) +
               query(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr);
    }
}

int main(void)
{
    ll q, ql, qr, type, tc = 1;
    while (scanf("%lld", &n) != EOF)
    {
        memset(seg, 0, sizeof(seg));
        for (ll i = 0; i < n; ++i)
            scanf("%lld", &a[i]);

        build(a, 1, 0, n - 1);
        scanf("%lld", &q);
        printf("Case #%lld:\n", tc++);
        while (q--)
        {
            scanf("%lld%lld%lld", &type, &ql, &qr);
            if (ql > qr)
                swap(ql, qr);

            if (type == 0)
            {
                update(1, 0, n - 1, ql - 1, qr - 1);
            }
            else
            {
                printf("%lld\n", query(1, 0, n - 1, ql - 1, qr - 1));
            }
        }
        printf("\n");
    }
    return 0;
}
