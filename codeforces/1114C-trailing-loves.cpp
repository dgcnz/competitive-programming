#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/sieve>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const   NMAX = 1e6 + 11;
Sieve<NMAX> sieve;

vector<pair<ll, ll>> prime_factorize(ll b)
{
    vector<pair<ll, ll>> ans;
    for (ll p : sieve.primes)
    {
        ll e = 0;
        if (p * p > b)
            break;
        while (b % p == 0)
        {
            b /= p;
            e++;
        }
        if (e)
            ans.emplace_back(p, e);
    }
    if (b > 1)
        ans.emplace_back(b, 1);

    return ans;
}

ll solve(ll n, ll b)
{
    ll   ans     = 1e18;
    auto factors = prime_factorize(b);
    for (auto [p, e] : factors)
    {
        ll nx = n;
        ll d  = 0;
        while (nx)
        {
            d += nx / p;
            nx /= p;
        }
        ans = min(ans, d / e);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, b;
    cin >> n >> b;
    cout << solve(n, b) << endl;
    return 0;
}
