#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/lazysegtree>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll const INF = 1e18;

struct S
{
    ll  sum, mx;
    int n;
};

S op(S a, S b) { return {a.sum + b.sum, max(a.mx, b.mx), a.n + b.n}; }

S e() { return {0, -INF, 0}; }

using F = ll;

F id() { return INF; }

S mapping(F f, S x) { return f == id() ? x : S{f * x.n, f, x.n}; }

F composition(F f, F g) { return f == id() ? g : f; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));
    vector<ll> k(n - 1);
    read(all(k));

    vector<ll> t(n, 0), b(n), pt(n, 0);
    partial_sum(all(k), next(begin(t)));
    partial_sum(all(t), begin(pt));
    auto sumt = [&pt](int l, int r) { return pt[r] - (l > 0 ? pt[l - 1] : 0); };

    for (int i = 0; i < n; ++i)
        b[i] = a[i] - t[i];

    vector<S> X(n);
    for (int i = 0; i < n; ++i)
        X[i] = {b[i], b[i], 1};

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(X);

    int q;
    cin >> q;
    while (q--)
    {
        char type;
        cin >> type;
        if (type == 's')
        {
            int l, r;
            cin >> l >> r, l--, r--;
            auto ans = seg.prod(l, r + 1);
            cout << ans.sum + sumt(l, r) << endl;
        }
        else
        {
            int i;
            ll  x;
            cin >> i >> x, i--;
            auto bi  = seg.get(i).sum + x;
            auto g   = [&bi](S x) { return x.mx < bi; };
            int  pos = seg.max_right(i, g);
            seg.apply(i, pos, bi);
        }
    }
    return 0;
}
