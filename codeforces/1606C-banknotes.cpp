#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/math/binary_exponentiation>
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

ll solve(vi a, int k)
{
    int        n = a.size();
    vector<ll> pten(19, 1);
    for (int i = 1; i < 19; ++i)
        pten[i] = pten[i - 1] * 10;

    auto f = [&](ll x)
    {
        ll ans = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            ll c = x / pten[a[i]];
            x -= c * pten[a[i]];
            ans += c;
        }
        return ans;
    };

    auto ok = [&](ll x) { return f(x) <= k; };

    ll x = 0;
    a.push_back(18);
    for (int i = 0; i < n; ++i)
    {
        itll l = 0, r = pten[a[i + 1]] / pten[a[i]];
        auto g = [&](ll j) { return x + j * pten[a[i]]; };
        auto j = *binary_search10(l, r, [&](ll j) { return ok(g(j)); });
        if (j < *r - 1)
            return x + (j + 1) * pten[a[i]];
        x += j * pten[a[i]];
    }
    return x;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi a(n);
        read(all(a));

        cout << solve(a, k) << endl;
    }
    return 0;
}
