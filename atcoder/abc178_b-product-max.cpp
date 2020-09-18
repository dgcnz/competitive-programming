#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans = max({a * c, a * d, b * c, b * d});
    cout << ans << endl;

    return 0;
}
