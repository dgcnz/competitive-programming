#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint998244353;

ll solve(int n, int k)
{
    vector<vector<mint>> dpbb(n + 1, vector<mint>(k + 2, 0));
    vector<vector<mint>> dpwb(n + 1, vector<mint>(k + 2, 0));
    vector<vector<mint>> dpbw(n + 1, vector<mint>(k + 2, 0));
    vector<vector<mint>> dpww(n + 1, vector<mint>(k + 2, 0));

    dpbb[1][1] = dpww[1][1] = 1;
    dpbw[1][2] = dpwb[1][2] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int c = 1; c <= k; ++c)
        {
            dpbb[i][c] = dpbb[i - 1][c] + dpwb[i - 1][c] + dpbw[i - 1][c] +
                         dpww[i - 1][c - 1];
            dpww[i][c] = dpww[i - 1][c] + dpwb[i - 1][c] + dpbw[i - 1][c] +
                         dpbb[i - 1][c - 1];
            if (c > 1)
            {
                dpbw[i][c] = dpbw[i - 1][c] + dpwb[i - 1][c - 2] +
                             dpbb[i - 1][c - 1] + dpww[i - 1][c - 1];
                dpwb[i][c] = dpwb[i - 1][c] + dpbw[i - 1][c - 2] +
                             dpbb[i - 1][c - 1] + dpww[i - 1][c - 1];
            }
        }
    }
    return (dpbb[n][k] + dpbw[n][k] + dpwb[n][k] + dpww[n][k]).val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    cout << solve(n, k) << endl;
    return 0;
}
