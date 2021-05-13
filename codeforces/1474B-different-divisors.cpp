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

int const   NMAX = 1e5;
Sieve<NMAX> sieve;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        ll a = *upper_bound(all(sieve.primes), d);
        ll b = *lower_bound(all(sieve.primes), a + d);
        cout << min(a * a * a, a * b) << endl;
    }
    return 0;
}
