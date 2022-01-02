#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll query(ll n, int k)
{
    if (n == 0LL)
        return 0;
    ll ans = (n >> (k + 1)) << k;
    if ((n >> k) & 1)
        ans += n & ((1ll << k) - 1);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int n = r - l + 1, ans = n;
        for (int i = 0; i < 30; ++i)
        {
            int cnt = query(r + 1, i) - query(l, i);
            ans     = min(ans, n - cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
