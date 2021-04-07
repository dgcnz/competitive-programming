#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll bs(ll l, ll r, function<bool(ll)> p)
{
    while (l < r)
    {
        ll m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

bool solve(vector<ll> a, vector<ll> b)
{
    int  n = a.size();
    auto f = [&](ll x) {
        ll prev_chosen = x, cur_chosen, ans = a[0];
        b[n - 1] -= (a[0] - x);
        for (int i = 1; i < n; ++i)
        {
            cur_chosen  = min(b[i - 1] - prev_chosen, a[i]);
            prev_chosen = max(0LL, min(b[i], a[i] - cur_chosen));
            cur_chosen += prev_chosen;
            ans += cur_chosen;
        }
        b[n - 1] += (a[0] - x);
        return ans;
    };
    auto ok = [&](ll x) { return f(x + 1) - f(x) <= 0; };
    if (b[n - 1] + b[0] < a[0])
        return false;
    ll l = max(0LL, a[0] - b[n - 1]), r = min(a[0], b[0]);
    ll p0 = bs(l, r, ok);
    return f(p0) >= accumulate(all(a), 0LL);
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
        vector<ll> a(n), b(n);
        for (auto &ai : a)
            cin >> ai;
        for (auto &bi : b)
            cin >> bi;

        cout << (solve(a, b) ? "YES" : "NO") << endl;
    }
    return 0;
}
