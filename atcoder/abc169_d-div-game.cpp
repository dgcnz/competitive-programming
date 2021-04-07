#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/sieve>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const   NMAX = 1e6 + 10;
Sieve<NMAX> sieve;

int solve(ll n)
{
    int ans = 0;
    for (ll p : sieve.primes)
    {
        if (p > n)
            break;

        ll x = p;
        while (n % x == 0)
        {
            n /= x;
            x *= p;
            ans++;
        }
        while (n % p == 0)
            n /= p;
    }
    if (n != 1)
        ans++;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
