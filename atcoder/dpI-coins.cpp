#include <iomanip>
#include <iostream>
#include <numeric>

// dp(i, j) : probability of getting j heads in i coin tosses
// dp(0, 0) = 1
// dp(0, _) = 0
// dp(i, 0) = (1 - p[i]) * dp(i - 1, 0)
// dp(i, j) = p[i] * dp(i - 1, j - 1) + (1 - p[i]) * dp(i - 1, j)

using namespace std;

const int NMAX = 3e3 + 11;

int    n;
double p[NMAX], dp[NMAX][NMAX];

double solve(void)
{
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        dp[0][i] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            dp[i][j] = (1 - p[i]) * dp[i - 1][j];
            if (j != 0)
                dp[i][j] += p[i] * dp[i - 1][j - 1];
        }
    }

    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= n; ++j)
    //     {
    //     }
    // }
    // double ans = 0;
    // for (int j = (n / 2) + 1; j <= n; ++j)
    //    ans += dp[n][j];
    return accumulate(dp[n] + n / 2 + 1, dp[n] + n + 1, 0.0);
}

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    cout << setprecision(10) << solve() << endl;
    return 0;
}
