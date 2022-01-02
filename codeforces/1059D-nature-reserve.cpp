#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> x(n), y(n);

    auto f = [&](long double r)
    {
        long double mn = -1e15, mx = 1e15;
        for (int i = 0; i < n; ++i)
        {
            if (2 * r - y[i] < 0)
                return false;
            long double b = sqrt(2 * r - y[i]) * sqrt(y[i]);
            mn            = max(mn, x[i] - b);
            mx            = min(mx, x[i] + b);
        }
        return mn <= mx;
    };

    bool pos = 0, neg = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
        if (y[i] < 0)
        {
            y[i] *= -1;
            neg = 1;
        }
        else
            pos = 1;
    }
    if (pos && neg)
    {
        cout << -1;
        return 0;
    }
    int         cnt = 80;
    long double s = 0, e = 1e16, md, ans = -1;
    while (cnt--)
    {
        md = (s + e) / 2;
        if (f(md))
            ans = e = md;
        else
            s = md;
    }
    cout << fixed << setprecision(7) << ans;

    return 0;
}
