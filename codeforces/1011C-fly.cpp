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

double solve(vi a, vi b, int m)
{
    int n = a.size();
    // remaining fuel after all travel
    auto f = [&](double fw) -> double {
        double x = (fw + m) / a[0];
        if (x > fw)
            return -1.0;
        fw -= x;

        for (int i = 1; i < n; ++i)
        {
            x = (fw + m) / b[i];
            if (x > fw)
                return -1.0;
            fw -= x;
            x = (fw + m) / a[i];
            if (x > fw)
                return -1.0;
            fw -= x;
        }
        x = (fw + m) / b[0];
        if (x > fw)
            return -1.0;
        fw -= x;
        return fw;
    };

    auto p = [&](double fw) { return f(fw) >= 0.0; };

    double const INF = 2e9f;
    double       l = 0.0f, r = INF;
    int          iterations = 200;
    for (int i = 0; i < iterations; ++i)
    {
        double mid = 0.5f * (l + r);
        if (p(mid))
            r = mid;
        else
            l = mid;
    }
    return l == INF ? -1 : l;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    read(all(a)), read(all(b));

    auto ans = solve(a, b, m);
    if (ans == -1.0)
        cout << -1 << endl;
    else
        cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
