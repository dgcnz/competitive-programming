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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n;
    vector<ll> a(n), dp(n);
    read(all(a));
    cin >> q;

    ll ans = a[0];
    for (int i = 1; i < n; ++i)
        ans = a[i] - ans;

    while (q--)
    {
        int l, r;
        ll  v;
        cin >> l >> r >> v, l--, r--;
        int evens = r / 2 - (l + 1) / 2 + 1;
        int odds  = r - l + 1 - evens;
        int k     = n % 2 == 0 ? -1 : +1;

        ans += v * k * (evens - odds);
        cout << ans << endl;
    }
    return 0;
}
