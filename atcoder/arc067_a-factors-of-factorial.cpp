#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/math/sieve>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using namespace cplib;
using ll         = long long;
using ii         = pair<int, int>;
using vi         = vector<int>;
using mint       = modint1000000007;
int const   NMAX = 1e3;
Sieve<NMAX> sieve;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    mint ans = 1;
    for (ll p : sieve.primes)
    {
        if (p > n)
            break;
        ll pe = p, e = 0;
        while (pe <= n)
        {
            e += n / pe;
            pe *= p;
        }
        ans *= (e + 1);
    }
    cout << ans.val() << endl;

    return 0;
}
