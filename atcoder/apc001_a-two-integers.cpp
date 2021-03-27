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
ll solve(ll x, ll y)
{
    ll g = gcd(x, y);
    if (g == y)
        return -1;
    else
        return x;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll x, y;
    cin >> x >> y;

    cout << solve(x, y) << endl;

    return 0;
}
