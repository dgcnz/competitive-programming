#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/sieve>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const                NMAX = 2e7 + 11;
SmallestPrimeSieve<NMAX> sieve;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    vector<int> np(NMAX);
    for (int i = 2; i < NMAX; ++i)
    {
        int j = i / sieve.sp[i];
        np[i] = np[j] + (sieve.sp[i] != sieve.sp[j]);
    }

    int t;
    cin >> t;
    while (t--)
    {

        int c, d, x;
        cin >> c >> d >> x;

        int ans = 0;
        for (int g = 1; g * g <= x; ++g)
        {
            if (x % g != 0)
                continue;
            int k1 = x / g + d;
            if (k1 % c == 0)
                ans += 1 << np[k1 / c];
            if (g * g == x)
                continue;
            int k2 = g + d;
            if (k2 % c == 0)
                ans += 1 << np[k2 / c];
        }
        cout << ans << endl;
    }
    return 0;
}
