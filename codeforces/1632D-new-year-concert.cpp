#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct S
{
    int n, g;
};
S op(S a, S b) { return S{a.n + b.n, gcd(a.g, b.g)}; }
S e() { return {0, 0}; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    read(all(a));

    int const                  DUMMY = 1e9 + 7;
    atcoder::segtree<S, op, e> st(n);

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1)
            st.set(i, {1, a[i] = DUMMY});
        else
        {
            st.set(i, {1, a[i]});
            auto f = [](S x) { return x.g >= x.n; };
            if (int l = st.min_left(i + 1, f); i + 1 != l)
            {
                S x = st.prod(l, i + 1);
                if (x.g == x.n)
                    st.set(i, {1, a[i] = DUMMY});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += a[i] == DUMMY;
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
