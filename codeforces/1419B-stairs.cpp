#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll        = unsigned long long;
using ii        = pair<int, int>;
using vi        = vector<int>;
using predicate = function<bool(ll)>;

ll x;
ll sq(ll n) { return (n * (n + 1)) / 2; }

int bs(ll l, ll r, predicate p)
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

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> x;
        // ll n = bs(0, 1e9, [](ll a) { return sq(a) <= x; });

        ll y = 2, ans = 0;
        while (sq(y - 1) <= x)
        {
            ans += 1;
            x -= sq(y - 1);
            y <<= 1;
        }

        cout << ans << endl;
    }
    return 0;
}
