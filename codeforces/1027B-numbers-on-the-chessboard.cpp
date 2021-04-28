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
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y, x--, y--;
        if ((x + y) % 2 == 0)
        {
            ll ans = ceil(x * n, 2) + ceil(y + 1, 2);
            cout << ans << endl;
        }
        else
        {
            ll ans = ceil(n * n, 2) + (x * n) / 2 + ceil(y + 1, 2);
            cout << ans << endl;
        }
    }
    return 0;
}
