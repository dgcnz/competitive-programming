#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<ll> a, vector<ll> b)
{
    int        n = a.size();
    vector<ll> sa(n), sb(n);
    partial_sum(rall(a), rbegin(sa));
    partial_sum(rall(b), rbegin(sb));

    vector<ll> dpa(n, 0), dpb(n, 0);
    dpa[n - 1] = b[n - 1];
    dpb[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        dpa[i] =
            dpa[i + 1] + sa[i + 1] + sb[i + 1] + (2 * n - 2 * i - 1) * b[i];
        dpb[i] =
            dpb[i + 1] + sa[i + 1] + sb[i + 1] + (2 * n - 2 * i - 1) * a[i];
    }

    ll ans = 0, cur = 0;
    for (int i = 0; i < n; ++i)
    {
        int time      = (2 * i);
        ll  increment = time * (sa[i] + sb[i]);
        if (i % 2 == 0)
        {
            ans = max(ans, cur + dpa[i] + increment);
            cur += time * a[i] + (time + 1) * b[i];
        }
        else
        {
            ans = max(ans, cur + dpb[i] + increment);
            cur += time * b[i] + (time + 1) * a[i];
        }
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    read(all(a));
    read(all(b));

    cout << solve(a, b) << endl;
    return 0;
}
