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

ll solve(ll n, ll k)
{
    ll r = min(k - 1, n), l = k - r;
    if (l >= r or l <= 0)
        return 0;
    return (r - l + 1) / 2;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
