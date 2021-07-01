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
    int t;
    cin >> t;

    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll c1, c2, c3, c4, c5, c6;
        ll n1, n2, n3, n4, n5, n6;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
        n1     = min(c1, c2 + c6);
        n2     = min(c2, c1 + c3);
        n3     = min(c3, c2 + c4);
        n4     = min(c4, c3 + c5);
        n5     = min(c5, c4 + c6);
        n6     = min(c6, c1 + c5);
        ll ans = 0;
        if (x >= 0 and y >= 0)
        {
            ll d = min(x, y);
            ans += d * n1;
            x -= d;
            y -= d;
            if (x > 0)
                ans += n6 * x;
            if (y > 0)
                ans += n2 * y;
        }
        else if (x <= 0 and y >= 0)
        {
            x = -x;
            ans += y * n2;
            ans += x * n3;
        }
        else if (x <= 0 and y <= 0)
        {
            x    = -x;
            y    = -y;
            ll d = min(x, y);
            ans += d * n4;
            x -= d;
            y -= d;
            if (x > 0)
                ans += x * n3;
            if (y > 0)
                ans += y * n5;
        }
        else if (x >= 0 and y <= 0)
        {
            y = -y;
            ans += x * n6;
            ans += y * n5;
        }
        cout << ans << "\n";
    }
    return 0;
}
