#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll        = long long;
using ii        = pair<int, int>;
using vi        = vector<int>;
using predicate = function<bool(ll)>;

ll n, m, k;

ll n_smaller(ll x)
{
    ll ans = 0;
    for (int row = 1; row <= n; ++row)
        ans += min((x - 1) / row, m);

    return ans;
}

// 1 1 1 0 0 0 : last yes
ll bs(ll lo, ll hi, predicate p)
{
    while (lo < hi)
    {
        ll mid = lo + (hi - lo + 1) / 2;
        if (p(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int main(void)
{
    cin >> n >> m >> k;
    cout << bs(1, 1e12, [](ll x) { return n_smaller(x) < k; }) << endl;
    return 0;
}
