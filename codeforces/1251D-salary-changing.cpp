#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;

ll bs(ll l, ll r, function<bool(ll)> p)
{
    while (l < r) // 111000
    {
        ll m = l + (r - l + 1) / 2;
        if (p(m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

ll solve(vector<pll> lr, ll s)
{
    ll const INF = 1e16;
    sort(all(lr), greater<pll>());

    int n       = lr.size();
    ll  m0      = lr[n / 2].first,
       min_cost = accumulate(
           all(lr), 0LL, [](ll acc, auto lri) { return acc + lri.first; });

    auto extra_cost = [&](ll m) {
        int cnt = n / 2 + 1;
        ll  ans = 0;
        for (int i = 0; i < n; ++i)
            if (cnt and lr[i].second >= m)
                ans += max(0LL, m - lr[i].first), cnt--;
        return cnt ? INF : ans;
    };

    auto p = [&](ll m) -> bool { return min_cost + extra_cost(m) <= s; };
    return bs(m0, s, p);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll  s;
        cin >> n >> s;
        vector<pll> lr(n);
        for (auto &[l, r] : lr)
            cin >> l >> r;

        cout << solve(lr, s) << endl;
    }
    return 0;
}
