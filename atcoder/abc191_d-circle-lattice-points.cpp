#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll    = int64_t;
using ii    = pair<int, int>;
using vi    = vector<int>;
using Point = complex<double>;

ll const F = 10000;

ll INT_CEIL(ll x) { return (x % F == 0) ? x : (x / F + (x >= 0)) * F; }
ll INT_FLOOR(ll x) { return (x % F == 0) ? x : (x / F - (x < 0)) * F; }

ll solve(ll x0, ll y0, ll r)
{
    ll ymin = INT_FLOOR(y0 - r - F), ymax = INT_CEIL(y0 + r + F), ans = 0;
    for (ll y = ymin; y <= ymax; y += F)
    {
        if (abs(y0 - y) > r)
            continue;

        auto ok = [y, x0, y0, r](ll x) {
            return (x - x0) * (x - x0) + (y - y0) * (y - y0) <= r * r;
        };

        itll xmin(x0 - r - F), xmid(x0), xmax(x0 + r + F);
        ll   l = *binary_search01(xmin, xmid, ok);
        ll   r = *binary_search10(xmid, xmax, ok);

        l = INT_CEIL(l);
        r = INT_FLOOR(r);
        if (r >= l)
            ans += r / F - l / F + 1;
    }
    return ans;
}
ll read()
{
    string s;
    cin >> s;
    string a = "";
    string b(4, '0');
    int    pos = s.size();
    for (int i = 0, n = s.size(); i < n; i++)
    {
        if (s[i] == '.')
        {
            pos = i;
            break;
        }
        a += s[i];
    }
    for (int i = pos + 1, n = s.size(); i < n; i++)
        b[i - pos - 1] = s[i];
    return stoll(a + b);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll x0 = read();
    ll y0 = read();
    ll r  = read();

    cout << solve(x0, y0, r) << endl;

    return 0;
}
