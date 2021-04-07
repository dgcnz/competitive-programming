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
    ll n, m, ans = 0;

    cin >> n >> m;
    for (ll g = 1; g * g <= m; ++g)
    {
        if (m % g == 0)
        {
            ll k = m / g;
            if (k >= n)
                ans = max(ans, g);
            if (g >= n)
                ans = max(ans, k);
        }
    }
    cout << ans << endl;
    return 0;
}
