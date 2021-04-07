#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/binary_exponentiation.hpp>
#include <cplib/math/sieve>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 1e6 + 11;

Sieve<NMAX> sieve;

ll solve(ll n, ll x)
{
    ll ans = 1;
    if (n == 1)
        return x;
    for (ll p : sieve.primes)
    {
        if (p > x)
            break;
        ll cnt = 0;
        while (x % p == 0)
        {
            x /= p;
            ++cnt;
        }
        ans *= binpow(p, cnt / n);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, p;
    cin >> n >> p;
    cout << solve(n, p) << endl;
    return 0;
}
