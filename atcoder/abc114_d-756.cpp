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

int const   NMAX = 1e3;
Sieve<NMAX> sieve;

int solve(int n)
{
    vector<int> exp;
    for (ll p : sieve.primes)
    {
        ll pk = p, e = 0;
        if (n / p == 0)
            break;
        while (n / pk)
        {
            e += n / pk;
            pk *= p;
        }
        exp.push_back(e);
    }
    auto num = [&](int m) {
        return count_if(all(exp), [m](int e) { return e >= m - 1; });
    };

    return num(75) + num(25) * (num(3) - 1) + num(15) * (num(5) - 1) +
           num(5) * (num(5) - 1) * (num(3) - 2) / 2;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    cout << solve(n) << endl;
    return 0;
}
