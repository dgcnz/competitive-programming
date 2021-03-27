#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll a, b;
    cin >> a >> b;

    pair<ll, ll> ans = {lcm(a, b), 0};
    if (a < b)
        swap(a, b);
    for (ll g = 1; g * g <= a - b; ++g)
    {
        if ((a - b) % g == 0)
        {
            ll k = g - (a % g);
            ans  = min(ans, {lcm(a + k, b + k), k});

            ll g2 = (a - b) / g;
            k     = g2 - (a % g2);
            ans   = min(ans, {lcm(a + k, b + k), k});
        }
    }
    cout << ans.second << endl;

    return 0;
}
