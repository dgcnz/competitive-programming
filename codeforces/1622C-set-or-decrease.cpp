#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll iceil(ll a, ll b) { return (a + b - 1) / b; }

ll solve(vector<ll> a, ll k)
{
    int n = a.size();
    sort(all(a));

    ll total_sum = accumulate(all(a), 0LL);
    if (total_sum <= k)
        return 0;

    ll ans = total_sum - k, suffix_sum = 0;
    for (int i = n - 1; i > 0; --i)
    {
        ll m = n - i;
        suffix_sum += a[i];
        ll cur = max(0LL, total_sum - suffix_sum + m * a[0] - k);
        ll x   = max(0LL, iceil(cur, m + 1));
        ans    = min(ans, x + m);
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll  k;
        cin >> n >> k;
        vector<ll> a(n);
        read(all(a));

        cout << solve(a, k) << endl;
    }
    return 0;
}
