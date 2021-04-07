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

ll solve(ll b)
{
    ll ans = 0;
    for (ll g = 1; g * g <= b; ++g)
    {
        if (b % g == 0)
        {
            ll d = b / g;
            ans += d == g ? 1 : 2;
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll b;
    cin >> b;
    cout << solve(b) << endl;
    return 0;
}
