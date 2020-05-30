#include <algorithm>
#include <iostream>

using namespace std;

const int NMAX = 2e5 + 11;
int       n, p, k, a[NMAX], dp[NMAX];

// @idea:
//  dp(i) : cost of picking i items
//  dp(i) =  dp(i - k) + a[i]    if x - k >= 0
//           dp(i - 1) + a[i]    otherwise
//
//  ans = max({i | i <- [1,2..n], dp(i) <= p})

int solve(void)
{
    int ans = 0;

    dp[0] = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = a[i];
        if (i - k >= 0)
            dp[i] += dp[i - k];
        else
            dp[i] += dp[i - 1];
    }

    for (int i = 1; i <= n; ++i)
    {
        // cout << dp[i] << " ";
        if (dp[i] <= p)
            ans = max(ans, i);
    }
    // cout << endl;
    return ans;
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> p >> k;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        cout << solve() << endl;
    }
    return 0;
}
