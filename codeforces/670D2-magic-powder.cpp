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
        ll m = l + (r - l + 1) / 2;
        if (p(m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

ll solve(int k, vi a, vi b)
{
    int n = a.size();

    auto ok = [&](ll cookies) {
        ll powder = k;
        for (int i = 0; i < n; ++i)
        {
            powder -= max(cookies * a[i] - b[i], 0LL);
            if (powder < 0)
                return false;
        }
        return true;
    };

    return bs(0, 2e9 + 11, ok);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;

    cout << solve(k, a, b) << endl;
    return 0;
}
