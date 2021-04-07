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

ll solve(ll n)
{
    ll ans = 0, denom = 5;
    if (n & 1)
        return 0;
    while (n >= 2 * denom)
    {
        ans += n / (2 * denom);
        denom *= 5;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
