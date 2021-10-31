#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i], a[i] = (a[i] >= m ? 1 : -1);

    int const   INF = 1e9;
    vector<int> dp(n + 1, -INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i, sum = 0; j > 0; --j)
        {
            sum += a[j];
            if (sum >= 1 and dp[j - 1] != -INF)
                dp[i] = max(dp[i], 1 + dp[j - 1]);
        }
    }
    if (dp[n] == -INF)
        dp[n] = 0;
    cout << dp[n] << endl;
    return 0;
}
