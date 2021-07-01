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
    int n = a.size();
    for (auto &ai : a)
        ai = abs(ai);

    sort(all(a));
    ll ans = 0;
    for (int i = 1; i < n; ++i)
    {
        ll   y  = (a[i] + 1) / 2;
        auto it = lower_bound(a.begin(), a.begin() + i, y);
        ans += distance(it, a.begin() + i);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));
    cout << solve(a) << endl;
    return 0;
}
