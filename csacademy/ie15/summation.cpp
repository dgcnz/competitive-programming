#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/math/combinatorics>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;
using vi  = vector<int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll  m, p, n;
    int q;
    cin >> p >> q >> n >> m;

    using mint = modint;
    mint::set_mod(m);



    bool as = 1;
    for (int i = 2; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            as = 0;
            break;
        }
    }

    if (as == 0 && n <= 10000000)
    {
        ll ans6 = 0;
        for (int k = 1; k < n + 1; ++k)
        {
            ans6 = (ans6 + (pot(p, k, m) * pot(k, q, m)) % m + m) % m;
        }
        cout << ans6;
        return 0;
    }
    fac[0] = 0;
    for (int i = 1; i < q + 4; ++i)
    {
        fac[i] = (fac[i - 1] + (pot(p, i, m) * pot(i, q, m)) % m) % m;
    }

    ll nb = 1;
    for (int i = 0; i < q + 4; ++i)
    {
        if (i == n)
            continue;
        nb = (nb * ((n - i) % m + m) % m) % m;
    }

    ll d = 1;
    for (int i = 1; i <= q + 1; i++)
    {
        d = (d * ((-i) % m + m) % m) % m;
    }

    ll ans = 0;
    for (int i = 1; i < q + 2; ++i)
    {
        ll t1 = 0;

        if (q + 1 < n)
        {
            t1 = (nb * inv(((n - i) % m + m) % m, m)) % m;
        }
        else if (i == n)
        {
            t1 = nb;
        }

        ans = (ans + (fac[i] * ((t1 * inv(d, m)) % m)) % m) % m;

        d = (d * inv(((i - (q + 1)) % m + m) % m, m)) % m;
        d = (d * (i + 1)) % m;
    }

    cout << ans;

    return 0;
}
