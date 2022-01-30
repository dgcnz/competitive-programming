#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        ll n = r - l + 1;
        if (n == 1)
        {
            cout << (l > 1 ? "YES" : "NO") << endl;
        }
        else
        {
            ll x = range_remainder_count(l, r, 2, 0);
            ll y = n - x;
            // dbg(x, y, k);
            cout << (y <= k ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
