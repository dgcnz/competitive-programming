#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using ii   = pair<ll, ll>;
using vi   = vector<int>;
using mint = modint1000000007;

vector<ii> compute_xm()
{
    ll const   NMAX = 1e16;
    vector<ii> xm;

    ll lp = 2;
    ll x  = 3;
    ll cp = 3;
    while (lp <= NMAX)
    {
        if (lp % x == 0)
        {
            x++;
            continue;
        }

        ll l = lcm(lp, x);

        ll c = cp + 1;
        while (l % c == 0)
            c++;

        xm.emplace_back(l, c - cp);
        x++;
        lp = l;
        cp = c;
    }
    return xm;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    auto xm = compute_xm();
    int  t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        mint ans = 2 * ((n + 1) / 2) + 3 * (n / 2);
        for (auto [x, m] : xm)
            ans += m * (n / x);

        cout << ans.val() << endl;
    }
    return 0;
}
