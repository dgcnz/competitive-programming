#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

ll     n, m;
string s, t;

ll cost(char c1, char c2)
{
    if (c1 == c2 and c1 != ' ')
        return 0;
    if (c1 == c2 and c1 == ' ')
        return 1e7;
    if (c1 == ' ' or c2 == ' ')
        return 3;
    if (c1 < c2)
        swap(c1, c2);
    if (c1 == 'G')
    {
        if (c2 == 'A' or c2 == 'T')
            return 5;
        else
            return 4;
    }
    if (c1 == 'T')
        return 5;
    else // C
        return 5;
}

ll solve(void)
{
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, (ll)1e9));

    dp[0][0] = 0;
    for (ll i = 1; i <= n; ++i)
        dp[i][0] = dp[i - 1][0] + cost(s[i - 1], ' ');
    for (ll j = 1; j <= m; ++j)
        dp[0][j] = dp[0][j - 1] + cost(' ', t[j - 1]);
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1; j <= m; ++j)
        {
            ll &ans = dp[i][j];
            ans     = dp[i - 1][j - 1] + cost(s[i - 1], t[j - 1]);
            ans     = min(ans, dp[i - 1][j] + cost(s[i - 1], ' '));
            ans     = min(ans, dp[i][j - 1] + cost(' ', t[j - 1]));
        }
    }

    return dp[n][m];
}

int main(void)
{
    while (cin >> s >> t)
    {
        n = s.size(), m = t.size();
        cout << solve() << endl;
    }
    return 0;
}
