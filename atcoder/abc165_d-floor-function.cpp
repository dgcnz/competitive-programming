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

ll solve(ll a, ll b, ll n)
{
    auto f = [&](ll x) { return (a * x) / b - a * (x / b); };
    if (n < b)
        return f(n);
    else
        return f(b - 1);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll a, b, n;
    cin >> a >> b >> n;

    cout << solve(a, b, n) << endl;
    return 0;
}
