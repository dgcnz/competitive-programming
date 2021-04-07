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

ll solve(ll k, ll a, ll b)
{
    if (b - a <= 2)
        return k + 1;

    ll ans = 1;
    ans += min(k, a - 1);
    k -= min(k, a - 1);
    ans += (b - a) * (k / 2);
    k %= 2;
    ans += k;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll k, a, b;
    cin >> k >> a >> b;
    cout << solve(k, a, b) << endl;
    return 0;
}
