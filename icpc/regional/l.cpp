#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/utils>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

pair<ll, int> solve(vector<ii> sd, int x)
{
    vector<ll>  rem(x, 0);
    int const   AMAX = 2e5 + 11;
    vector<int> actcnt(AMAX, 0);

    for (auto [s, d] : sd)
        actcnt[s]++, actcnt[s + d + 1]--;

    partial_sum(all(actcnt), begin(actcnt));

    ll const      INF = 1e15;
    pair<ll, int> ans = {INF, 0};
    for (int i = AMAX - 1; i >= 0; --i)
    {
        rem[i % x] += actcnt[i];
        if (i < 480)
            ans = min(ans, {rem[i % x], i});
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, x;
    cin >> n >> x;

    vector<ii> sd(n);
    for (auto &[s, d] : sd)
        cin >> s >> d;

    auto ans = solve(sd, x);
    cout << ans.second << " " << ans.first << endl;
    return 0;
}
