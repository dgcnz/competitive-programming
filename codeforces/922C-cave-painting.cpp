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

string solve(ll n, ll k)
{
    n += 1;
    for (ll i = 1; i <= k; ++i)
        if (n % i)
            return "No";
    return "Yes";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
