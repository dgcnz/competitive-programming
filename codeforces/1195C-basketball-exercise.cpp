#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<ll> h1, vector<ll> h2)
{
    int        n = h1.size();
    vector<ll> dp1(n, 0), dp2(n, 0);
    dp1[n - 1] = h1[n - 1], dp2[n - 1] = h2[n - 1];
    ll max_dp1 = dp1[n - 1], max_dp2 = dp2[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        dp1[i]  = h1[i] + max_dp2;
        dp2[i]  = h2[i] + max_dp1;
        max_dp1 = max(max_dp1, dp1[i]);
        max_dp2 = max(max_dp2, dp2[i]);
    }
    return max(max_dp1, max_dp2);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> h1(n), h2(n);
    read(all(h1));
    read(all(h2));

    cout << solve(h1, h2) << endl;
    return 0;
}
