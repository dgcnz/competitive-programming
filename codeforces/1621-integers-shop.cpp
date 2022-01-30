#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;
using vi  = vector<int>;

bool contained(ii a, ii b)
{
    return b.first <= a.first and a.second <= b.second;
}

vi solve(vector<iii> seg)
{
    int const   INF = 2e9;
    int         n   = seg.size();
    iii         mn = {INF, INF, INF}, mx = {-INF, -INF, -INF};
    ii          one = {-INF, -INF};
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
    {
        auto [l, r, c] = seg[i];
        mn             = min(mn, {l, c, -r});
        mx             = max(mx, {r, -c, -l});
        one            = max(one, {r - l + 1, -c});
        int mnl = get<0>(mn), mnr = -get<2>(mn), mnc = get<1>(mn);
        int mxl = -get<2>(mx), mxr = get<0>(mx), mxc = -get<1>(mx);
        ii  a   = {mnl, mnr};
        ii  b   = {mxl, mxr};
        int len = 0;
        if (contained(a, b) and contained(b, a))
        {
            len    = mxr - mxl + 1;
            ans[i] = min(mnc, mxc);
        }
        else if (contained(a, b))
        {
            len    = mxr - mxl + 1;
            ans[i] = mxc;
        }
        else if (contained(b, a))
        {
            len    = mnr - mnl + 1;
            ans[i] = mnc;
        }
        else
        {
            len    = mxr - mnl + 1;
            ans[i] = mnc + mxc;
        }
        if (len <= one.first)
            ans[i] = min(ans[i], -one.second);
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
        int n;
        cin >> n;
        vector<iii> seg(n);
        for (auto &[l, r, c] : seg)
            cin >> l >> r >> c;

        auto ans = solve(seg);

        write(all(ans));
    }
    return 0;
}
