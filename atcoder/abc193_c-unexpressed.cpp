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
    ll n;
    cin >> n;

    set<ll> numbers;
    for (ll a = 2; a * a <= n; ++a)
    {
        ll x = a * a;
        while (x <= n)
        {
            numbers.insert(x);
            x *= a;
        }
    }

    ll ans = n - numbers.size();
    cout << ans << endl;
    return 0;
}
