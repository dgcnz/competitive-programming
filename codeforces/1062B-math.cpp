#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/sieve>
#include <cplib/math/utils>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const   NMAX = 1e3 + 11;
Sieve<NMAX> sieve;

ii solve(int n)
{
    if (n == 1)
        return {1, 0};

    auto factors = prime_factorize(n, sieve.primes);
    int  m       = 1;
    vi   a;
    for (auto [p, e] : factors)
    {
        m *= p;
        a.push_back(e);
    }
    sort(all(a));

    ll x = 1, cnt = 0;
    while (x < a.back())
        x <<= 1, cnt++;

    return {m, cnt + (count(all(a), x) != (int)a.size())};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    auto [x, steps] = solve(n);
    cout << x << " " << steps << endl;
    return 0;
}
