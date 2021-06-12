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
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;
using vi  = vector<int>;

using S = ll;
S op(S a, S b) { return max(a, b); }
S e() { return 0LL; }

ll solve(vector<iii> bah)
{
    int       n   = bah.size();
    int const INF = 1e9 + 11;

    segtree<S, op, e> dp(n);
    sort(all(bah));

    dp.set(0, get<2>(bah[0]));
    for (int i = 1; i < n; ++i)
    {
        auto [b, a, h] = bah[i];

        int l = distance(
            bah.begin(),
            upper_bound(bah.begin(), bah.begin() + i + 1, iii{a, INF, INF}));
        if (l == i)
            dp.set(i, h);
        else
            dp.set(i, h + dp.prod(l, i));
    }
    return dp.all_prod();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<iii> bah(n);
    for (auto &[b, a, h] : bah)
        cin >> a >> b >> h;
    cout << solve(bah) << endl;
    return 0;
}
