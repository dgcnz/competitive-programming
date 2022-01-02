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

ll sq(ll x) { return (x * (x + 1)) / 2; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll  x;
    cin >> n >> x;
    vector<ll> d(2 * n);
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i];
        d[n + i] = d[i];
    }

    int l        = 0;
    ll  ans      = 0;
    ll  sum_days = 0;
    ll  sum_hugs = 0;
    for (int r = 0; r < 2 * n; ++r)
    {
        sum_days += d[r];
        sum_hugs += sq(d[r]);
        while (l < r and sum_days - d[l] >= x)
        {
            sum_days -= d[l];
            sum_hugs -= sq(d[l]);
            l++;
        }
        ans = max(ans, sum_hugs - sq(max(0LL, sum_days - x)));
    }
    cout << ans << endl;

    return 0;
}
