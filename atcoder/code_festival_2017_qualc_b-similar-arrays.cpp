#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<vi> dp(n, vi(2, 0));
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        int odds  = (a % 2 ? 1 : 2);
        int evens = (a % 2 ? 2 : 1);
        if (i == 0)
        {
            dp[i][0] = evens;
            dp[i][1] = odds;
        }
        else
        {
            dp[i][0] = dp[i - 1][0] * (odds + evens) + dp[i - 1][1] * (evens);
            dp[i][1] = dp[i - 1][1] * odds;
        }
    }
    cout << dp[n - 1][0] << endl;
    return 0;
}
