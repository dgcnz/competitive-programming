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

bool solve(vector<ll> a)
{
    ll const   INF = 1e17;
    int        n   = a.size();
    vector<ll> pre(n), suf(n);
    pre[0] = a[0], suf[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
        pre[i] = a[i] - pre[i - 1] < 0 ? INF : a[i] - pre[i - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = a[i] - suf[i + 1] < 0 ? INF : a[i] - suf[i + 1];

    auto check = [INF](ll x, ll y) { return x == y and x >= 0 and x != INF; };
    for (int i = 0; i < n - 1; i++)
    {
        ll p = i > 0 ? pre[i - 1] : 0, s = i + 2 < n ? suf[i + 2] : 0;
        if (check(a[i] - p, a[i + 1] - s) or check(a[i + 1] - p, a[i] - s))
            return true;
    }
    return false;
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
        cout << (solve(a) ? "YES" : "NO") << endl;
    }
    return 0;
}
