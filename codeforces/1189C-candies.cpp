#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
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
struct S
{
    int candies, d;
};
S op(S a, S b)
{
    return {a.candies + b.candies + (a.d + b.d >= 10), (a.d + b.d) % 10};
}
S e() { return {0, 0}; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));
    segtree<S, op, e> st(n);
    for (int i = 0; i < n; ++i)
        st.set(i, {0, a[i]});
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r, l--;
        auto ans = st.prod(l, r);
        cout << ans.candies << endl;
    }
    return 0;
}
