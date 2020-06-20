#include <bits/stdc++.h>

using namespace std;
using ii  = pair<int, int>;
using vii = vector<ii>;

struct segtree
{
    // segtree_node = {unclosed_left_parenthesis, unclosed_right_parenthesis}
    int n;
    vii t;
    segtree(int _n) : n(_n) { t.resize(4 * _n); }
    segtree(const string &s) : segtree(s.size()) { build(s, 1, 0, n - 1); }
    void build(const string &s, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            if (s[tl] == '(')
                t[v] = {1, 0}; // 1 left parenthesis unmatched
            else
                t[v] = {0, 1}; // 1 right parenthesis unmatched
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(s, 2 * v, tl, tm);
            build(s, 2 * v + 1, tm + 1, tr);
            t[v] = merge(t[2 * v], t[2 * v + 1]);
        }
    }
    int accumulate_pair(ii a) const { return a.first + a.second; }
    ii  merge(ii a, ii b) const
    {
        return {b.first + max(0, a.first - b.second),
                a.second + max(0, b.second - a.first)};
    }
    int query(int ql, int qr) const
    {
        int unmatched = accumulate_pair((_query(1, 0, n - 1, ql, qr)));
        return (qr - ql + 1 - unmatched);
    }
    ii _query(int v, int tl, int tr, int ql, int qr) const
    {
        if (ql > qr)
            return {0, 0};
        else if (tl == ql and tr == qr)
            return t[v];

        int tm = (tl + tr) / 2;
        return merge(_query(2 * v, tl, tm, ql, min(tm, qr)),
                     _query(2 * v + 1, tm + 1, tr, max(ql, tm + 1), qr));
    }
};

int main(void)
{
    int    m, l, r;
    string s;

    cin >> s >> m;
    segtree st(s);

    while (m--)
    {
        cin >> l >> r;
        cout << st.query(l - 1, r - 1) << endl;
    }
    return 0;
}
