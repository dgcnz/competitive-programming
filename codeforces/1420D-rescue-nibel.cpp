#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;

ll const  MOD  = 998244353;
int const NMAX = 3e5 + 11;

ll fact[NMAX];
// ll  inv[NMAX];

void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < NMAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    // inv[1] = 1;
    // for (int i = 2; i < NMAX; ++i)
    //     inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
}

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x    = y1;
    y    = x1 - y1 * (a / b);
    return d;
}

ll inv(int a)
{
    ll x, y;
    ll g = gcd(a, MOD, x, y);
    if (g != 1)
    {
        return 0;
    }
    else
    {
        return (x % MOD + MOD) % MOD;
    }
}

ll C(ll n, ll k)
{
    // if (n == k)
    //     return 1;
    // else
    return fact[n] * inv(fact[k] * fact[n - k] % MOD) % MOD;
}

int main(void)
{
    ll n, k;
    cin >> n >> k;

    vector<ii> events(2 * n);
    for (int i = 0; i < n; ++i)
    {
        ll l, r;
        cin >> l >> r;
        events[2 * i]     = {l, -1};
        events[2 * i + 1] = {r, +1};
    }

    sort(all(events));
    precompute();

    ll turned = 0;
    ll ans    = 0;
    for (auto [t, sign] : events)
    {
        sign *= -1; // +1 open, -1 close

        if (sign == +1 and turned + sign >= k)
        {
            // compute all ways to choose k - 1 from the turned on
            // C(turned, k - 1) = O(C(n, n))
            ans += (C(turned, k - 1)) % MOD;
            // dbg(turned, k - 1, C(turned, k - 1));
        }
        turned += sign;
    }
    cout << ans % MOD << endl;
    return 0;
}
