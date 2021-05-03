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

ll solve(int n, ll a, ll b, string s)
{
    ll const   INF = 1e16;
    vector<ll> dp1(n + 1, INF), dp2(n + 1, INF);
    dp1[0] = b;
    for (int i = 1; i <= n; ++i)
    {
        dp2[i] = dp2[i - 1] + a;
        if (s[i - 1] == '0')
        {
            dp1[i] = min(dp1[i - 1] + a, dp2[i - 1] + 2 * a) + b;
            dp2[i] = min(dp2[i], dp1[i - 1] + 2 * a);
        }
        dp2[i] += 2 * b;
    }
    // dbg(dp1, dp2);
    return dp1[n];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int    n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        cout << solve(n, a, b, s) << endl;
    }
    return 0;
}
