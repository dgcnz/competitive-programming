#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ii get(ll a)
{
    ii ans = {10, -1};
    while (a)
    {
        ans.first  = min((ll)ans.first, a % 10);
        ans.second = max((ll)ans.second, a % 10);
        a /= 10;
    }
    return ans;
}

ll solve(ll a, ll k)
{
    k--;
    auto [mn, mx] = get(a);
    while (k-- and mn != 0)
    {
        a += mn * mx;
        tie(mn, mx) = get(a);
    }
    return a;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, k;
        cin >> a >> k;
        cout << solve(a, k) << endl;
    }
    return 0;
}
