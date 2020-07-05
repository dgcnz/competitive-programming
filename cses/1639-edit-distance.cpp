#include <bits/stdc++.h>

using namespace std;
using vi  = vector<int>;
using vvi = vector<vi>;

const int INF = 1e9 + 11;

int main(void)
{
    int    n, m;
    string s, t;
    cin >> s >> t;
    n = s.size(), m = t.size();

    vvi dp(n + 1, vi(m + 1, INF));

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
        dp[i][0] = i;
    for (int j = 1; j <= m; ++j)
        dp[0][j] = j;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int &ans = dp[i][j];
            ans      = min(
                {dp[i][j - 1] + 1,                            // insert
                 dp[i - 1][j] + 1,                            // delete
                 dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])}); // replacematch
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
