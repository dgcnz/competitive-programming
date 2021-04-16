#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

ll solve(ll n)
{
    auto p    = [n](ll a) { return a * a <= 2 * n - 1; };
    ll   amax = *binary_search10(itll(1), itll(n), p);
    return ceil(amax, 2) - 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
