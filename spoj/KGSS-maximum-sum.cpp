#include <bits/stdc++.h>

using namespace std;
using ii  = pair<int, int>;
using vi  = vector<int>;
using vii = vector<ii>;

inline int sum_pair(ii a) { return a.first + a.second; }

struct segtree
{
    int n;
    vii t;

    segtree(int n)
    {
        this->n = n;
        t.resize(4 * n);
    }
    segtree(const vi &a) : segtree(a.size()) { build(a, 1, 0, n - 1); }
    ii merge(ii a, ii b) const
    {
        if (a.first < b.first)
            swap(a, b);
        return {a.first, max({a.second, b.second, b.first})};
    }
    void build(const vi &a, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = {a[tl], -1}; // {maxnum, second_maxnum}
        else
        {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = merge(t[2 * v], t[2 * v + 1]);
        }
    }
    void update(int pos, int new_val)
    {
        update_util(1, 0, n - 1, pos, new_val);
    }
    void update_util(int v, int tl, int tr, int pos, int new_val)
    {
        if (pos < tl or tr < pos)
            return;
        else if (tl == tr and tl == pos)
            t[v] = {new_val, -1};
        else
        {
            int tm = (tl + tr) / 2;
            update_util(2 * v, tl, tm, pos, new_val);
            update_util(2 * v + 1, tm + 1, tr, pos, new_val);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    int query(int ql, int qr) const
    {
        return sum_pair(query_util(1, 0, n - 1, ql, qr));
    }
    ii query_util(int v, int tl, int tr, int ql, int qr) const
    {
        if (qr < ql)
            return {-1, -1};
        else if (ql == tl and qr == tr)
            return t[v];

        int tm = (tl + tr) / 2;
        return merge(query_util(2 * v, tl, tm, ql, min(tm, qr)),
                     query_util(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr));
    }
};

int main(void)
{
    int  n, qn, ql, qr, pos, x;
    char qtype;
    vi   a;

    cin >> n;
    a.resize(n);

    for (auto &x : a)
        cin >> x;

    segtree t(a);
    cin >> qn;

    while (qn--)
    {
        cin >> qtype;
        if (qtype == 'Q')
        {
            cin >> ql >> qr;
            cout << t.query(ql - 1, qr - 1) << endl;
        }
        else // 'U'
        {
            cin >> pos >> x;
            t.update(pos - 1, x);
        }
    }

    return 0;
}
