#include <iostream>

// @idea: digit dp
//      n       : total number of children
//      s       : current number of candies
//      i       : index of array a, starts at 1
//      acc[i]  : prefix sum up to i
//      dp(i, s): all the ways s candies can be distributed from [1...i]
//      dp(i, s) = sum [dp(i - 1, s - d) | d <- [0...a[i]]]

using namespace std;

const int NMAX = 1e2 + 11;
const int KMAX = 1e5 + 11;
const int MOD  = 1e9 + 7;

int n, k, a[NMAX], acc[KMAX], dp[NMAX][KMAX];

int solve(void)
{
    dp[0][0] = 1;

    for (int s = 1; s <= k; ++s)
        dp[0][s] = 0;

    for (int i = 1; i <= n; ++i)
    {
        // 1. If the prefix sum exceeds MOD, it will not be strictly increasing
        acc[0] = dp[i - 1][0];
        for (int s = 1; s <= k; ++s)
            acc[s] = (acc[s - 1] + dp[i - 1][s]) % MOD;
        // 2. reachable =  [s - a[i], s]
        for (int s = 0; s <= k; ++s)
            dp[i][s] =
                (acc[s] - (s - a[i] - 1 >= 0 ? acc[s - a[i] - 1] : 0) + MOD) %
                MOD; // take care of possible negative results. See 1.
    }

    return dp[n][k];
}

int main(void)
{
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    cout << solve() << endl;

    return 0;
}
