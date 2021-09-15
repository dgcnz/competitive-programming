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

vi solve(vector<vi> a)
{
    int n = a.size();

    vector<int> g(n);
    for (int i = 0; i < n; ++i)
        g[i] = accumulate(all(a[i]), 0, gcd<int, int>);

    auto attempt = [&](int x)
    {
        ll z = a[0][1] / x, y = a[0][2] / x;
        return a[1][2] == (z * y);
    };
    auto make = [&](int x)
    {
        vector<int> ans(n);
        ans[0] = x;
        for (int i = 1; i < n; ++i)
            ans[i] = a[i][0] / x;
        return ans;
    };

    for (ll x = 1; x * x <= g[0]; ++x)
    {
        if (g[0] % x == 0)
        {
            if (attempt(x))
                return make(x);
            if (attempt(g[0] / x))
                return make(g[0] / x);
        }
    }
    return {};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<vi> a(n, vi(n));

    for (int i = 0; i < n; ++i)
        read(all(a[i]));

    auto ans = solve(a);
    write(all(ans), " "), cout << endl;
    return 0;
}
