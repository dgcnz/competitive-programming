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
    ll const     INF = 1e17;
    ll           x;
    pair<ll, ll> ans = {INF, INF};
    cin >> x;
    for (ll a = 1; a * a <= x; ++a)
    {
        if (x % a == 0)
        {
            ll b = x / a;
            if (gcd(a, b) == 1 and max(a, b) < max(ans.first, ans.second))
                ans = {a, b};
        }
    }

    cout << ans.first << " " << ans.second << endl;
    return 0;
}
