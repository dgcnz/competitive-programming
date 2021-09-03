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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll  n, m;
    int q;
    cin >> n >> m >> q;

    ll   g  = gcd(n, m);
    ll   kn = n / g, km = m / g;
    auto f = [&](int x, ll y) { return y / (x == 1 ? kn : km); };

    while (q--)
    {
        int sx, ex;
        ll  sy, ey;
        cin >> sx >> sy >> ex >> ey, sy--, ey--;
        cout << (f(sx, sy) == f(ex, ey) ? "YES" : "NO") << endl;
    }
    return 0;
}
