#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (ll)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;

ll solve(ll r, ll x, ll y)
{
    ll rsq = x * x + y * y, R = r, k = 1;
    while (R * R < rsq)
        k++, R += r;
    if (k == 1 and R * R != rsq)
        return 2;
    return k;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll r, x, y;
    cin >> r >> x >> y;
    cout << solve(r, x, y) << endl;
    return 0;
}
