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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    read(all(a));

    ll const NMAX = 1e18 + 100;

    while (q--)
    {
        ll k;
        cin >> k;
        itll l(1), r(NMAX + n + 11);
        auto f = [&](ll x) {
            auto it = upper_bound(all(a), x);
            return x - distance(begin(a), it);
        };
        auto ok  = [&](ll x) { return f(x) >= k; };
        ll   ans = *binary_search01(l, r, ok);
        cout << ans << '\n';
    }
    return 0;
}
