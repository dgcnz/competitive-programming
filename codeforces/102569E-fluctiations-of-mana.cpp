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
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));

    itll l(0), r(1e17);

    auto p = [&](ll health) {
        for (int i = 0; i < n; ++i)
        {
            health += a[i];
            if (health < 0)
                return false;
        }
        return true;
    };

    ll ans = *binary_search01(l, r, p);
    cout << ans << endl;

    return 0;
}
