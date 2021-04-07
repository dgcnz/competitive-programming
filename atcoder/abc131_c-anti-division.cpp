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

ll  ceil(ll a, ll b) { return (a + b - 1) / b; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll l = lcm(c, d);

    ll ans = b / c - ceil(a, c) + 1;
    ans += b / d - ceil(a, d) + 1;
    ans -= b / l - ceil(a, l) + 1;
    cout << b - a + 1 - ans << endl;

    return 0;
}
