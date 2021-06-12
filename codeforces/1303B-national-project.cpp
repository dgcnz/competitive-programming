#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
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

ll solve(ll n, ll g, ll b)
{
    if (g >= b)
        return n;

    ll   INF = 1e18 + 11;
    itll l(n), r(INF);
    auto ok = [n, g, b](ll k) {
        ll good = (k / (g + b)) * g + min(g, (k % (g + b)));
        return good >= (n + 1) / 2;
    };

    ll k = *binary_search01(l, r, ok);
    return k;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, g, b;
        cin >> n >> g >> b;
        cout << solve(n, g, b) << endl;
    }
    return 0;
}
