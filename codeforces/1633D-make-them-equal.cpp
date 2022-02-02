#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/dp/knapsack01>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    // int const   XMAX = 1001;
    int const   XMAX = 1001;
    int const   INF  = 1e8;
    vector<int> f(XMAX, INF);

    // XMAX * sq(XMAX) = 1e5
    f[1] = 0;
    for (int x = 1; x < XMAX; ++x)
    {
        int sq = integer::sqrt(x);
        for (int i = 1; i <= sq; ++i)
            if (x + i < XMAX)
                f[x + i] = min(f[x + i], f[x] + 1);

        for (int i = 1; x / i > i; ++i)
            if (auto d = (x / i); x + d < XMAX)
                f[x + d] = min(f[x + d], f[x] + 1);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        read(all(b));
        read(all(c));

        vector<int> x(n);
        for (int i = 0; i < n; ++i)
            x[i] = f[b[i]];

        Knapsack01 dp(x, c, k);
        cout << dp.solve() << endl;
    }
    return 0;
}
