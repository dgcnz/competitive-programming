#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint1000000007;

int solve(int n)
{
    vector<vector<mint>> dpL(n + 1, vector<mint>(2, 0));
    vector<vector<mint>> dpR(n + 1, vector<mint>(2, 0));
    dpL[1][0] = dpR[1][0] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dpL[i][0] = dpR[i - 1][0] + dpR[i - 1][1];
        dpL[i][1] = dpL[i - 1][0];
        dpR[i][0] = dpL[i - 1][0] + dpL[i - 1][1];
        dpR[i][1] = dpR[i - 1][0];
    }
    return (dpL[n][0] + dpL[n][1] + dpR[n][0] + dpR[n][1]).val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    ll ansn = solve(n);
    ll ansm = solve(m) - 2;
    cout << mint(ansn + ansm).val() << endl;

    return 0;
}
