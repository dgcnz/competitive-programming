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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    for (int x = 2; x < n - 1; ++x)
    {
        if (!sieve.is_prime[x] and !sieve.is_prime[n - x])
        {
            cout << x << " " << n - x << endl;
            return 0;
        }
    }
    return 0;
}
