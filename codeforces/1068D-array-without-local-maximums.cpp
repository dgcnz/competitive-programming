#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint998244353;

ll solve(vi a)
{
    int                  n = a.size();
    vector<vector<mint>> dpgt(n, vector<mint>(201, 0));
    vector<vector<mint>> dplteq(n, vector<mint>(201, 0));
    vector<mint>         pdpgt(201, 0);
    vector<mint>         pdplteq(201, 0);

    if (a[0] == -1)
        fill(all(dplteq[0]), 1), dplteq[0][0] = 0;
    else
        dplteq[0][a[0]] = 1;

    partial_sum(all(dpgt[0]), pdpgt.begin());
    partial_sum(all(dplteq[0]), pdplteq.begin());
    for (int i = 1; i < n; ++i)
    {
        auto sumgt = [&](int l, int r) {
            if (l > r)
                return mint(0);
            return pdpgt[r] - (l > 0 ? pdpgt[l - 1] : mint(0));
        };
        auto sumlteq = [&](int l, int r) {
            if (l > r)
                return mint(0);
            return pdplteq[r] - (l > 0 ? pdplteq[l - 1] : mint(0));
        };

        for (int x = 1; x <= 200; ++x)
        {
            if (a[i] == -1 or x == a[i])
            {
                dpgt[i][x]   = sumlteq(x, x) + sumgt(x + 1, 200);
                dplteq[i][x] = sumlteq(1, x) + sumgt(x + 1, 200);
            }
        }
        partial_sum(all(dpgt[i]), pdpgt.begin());
        partial_sum(all(dplteq[i]), pdplteq.begin());
    }

    return pdpgt.back().val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &ai : a)
        cin >> ai;

    cout << solve(a) << endl;
    return 0;
}
