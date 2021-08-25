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

int const   NMAX = 1e5 + 10;
Sieve<NMAX> sieve;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vi> ans(n, vi(n, 1));
        auto       it = lower_bound(all(sieve.primes), n);
        if (*it != n)
        {
            int x;
            do
            {
                x = *it - n + 1;
                it++;
            } while (sieve.is_prime[x]);
            for (int i = 0; i < n; ++i)
                ans[i][i] = x;
        }
        for (auto &row : ans)
            write(all(row), " "), cout << endl;
    }
    return 0;
}
