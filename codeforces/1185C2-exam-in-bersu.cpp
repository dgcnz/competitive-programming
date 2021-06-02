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
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct S
{
    int cnt, sum;
};
S op(S a, S b) { return {a.cnt + b.cnt, a.sum + b.sum}; }
S e() { return {0, 0}; }

vi solve(vi t, int m)
{
    int const         tmax = 100 + 11;
    int               n    = t.size();
    segtree<S, op, e> st(tmax);

    vi ans(n);
    for (int i = 0; i < n; ++i)
    {
        int  sum = m - t[i];
        auto f   = [sum](S a) { return a.sum <= sum; };
        int  r   = st.max_right(0, f);
        if (r == tmax)
            ans[i] = 0;
        else
        {
            auto x         = st.prod(0, r);
            auto border    = st.get(r);
            int  underflow = x.sum, val = border.sum / border.cnt;
            ans[i] = x.cnt;
            itint first(0), last(border.cnt + 1);
            auto  p = [&](int k) { return underflow + k * (ll)val <= (ll)sum; };
            ans[i] += *binary_search10(first, last, p);
            ans[i] = i - ans[i];
        }

        auto x = st.get(t[i]);
        st.set(t[i], {x.cnt + 1, x.sum + t[i]});
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi t(n);
    read(all(t));
    auto ans = solve(t, m);
    write(all(ans), " "), cout << endl;
    return 0;
}
