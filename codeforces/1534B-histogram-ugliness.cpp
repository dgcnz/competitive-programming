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

ll solve(vector<ll> a)
{
    int n   = a.size();
    ll  ans = 0, prv = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += abs(a[i] - prv);
        prv = a[i];
    }
    ans += abs(a.back());
    for (int i = 0; i < n; ++i)
    {
        int l = (i > 0 ? a[i - 1] : 0), r = (i < n - 1 ? a[i + 1] : 0);
        ll  lim = max(l, r);
        if (a[i] > lim)
        {
            ans -= a[i] - lim;
            a[i] = lim;
        }
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
        cin >> n;
        vector<ll> a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
