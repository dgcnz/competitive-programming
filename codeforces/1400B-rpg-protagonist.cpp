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
        ll p, f;
        cin >> p >> f;
        ll cnts, cntw;
        cin >> cnts >> cntw;
        ll s, w;
        cin >> s >> w;

        if (s > w)
            swap(s, w), swap(cnts, cntw);

        ll ans = 0;
        for (ll ps = 0; ps <= cnts and ps * s <= p; ++ps)
        {
            ll pw   = (p - ps * s) / w;
            ll rems = (cnts - ps), remw = (cntw - pw);
            ll fs = min(f, rems * s) / s;
            ll fw = min(f - fs * s, remw * w) / w;
            ans   = max(ans, ps + pw + fs + fw);
        }
        cout << ans << endl;
    }
    return 0;
}
