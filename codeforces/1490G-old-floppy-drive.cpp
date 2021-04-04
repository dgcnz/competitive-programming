#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using S = ll;
S op(S a, S b) { return max(a, b); }
S e() { return -1e17; }
using MaxSegtree = atcoder::segtree<S, op, e>;

vector<ll> solve(vector<ll> a, vector<ll> x)
{
    int        n = a.size(), m = x.size();
    vector<ll> pa(n), ans(m);
    partial_sum(all(a), begin(pa));
    MaxSegtree st(pa);

    ll pa_max = st.all_prod(); // 10^14
    for (int i = 0; i < m; ++i)
    {
        ll k = 0;
        if (pa[n - 1] > 0)
        {
            auto p = [&](ll kk) { return kk * pa[n - 1] >= x[i] - pa_max; };
            auto l = itll(0), r = itll((x[i] - pa_max) / pa[n - 1] + 100);
            k = *binary_search01(l, r, p);
        }
        auto p = [&](S a) { return a < x[i] - k * pa[n - 1]; };
        ans[i] = st.max_right(0, p);
        ans[i] = ans[i] == n ? -1 : ans[i] + k * n;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n), x(m);
        read(all(a));
        read(all(x));
        auto ans = solve(a, x);
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
