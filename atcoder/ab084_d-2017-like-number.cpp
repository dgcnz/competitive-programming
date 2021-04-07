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

int const NMAX = 2e5 + 11;

Sieve<NMAX> sieve;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    vector<int> is2017(NMAX, 0);
    for (ll p : sieve.primes)
        if (2 * p - 1 < NMAX and sieve.is_prime[2 * p - 1])
            is2017[2 * p - 1] = 1;

    vector<int> sum(NMAX);
    partial_sum(all(is2017), begin(sum));

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}
