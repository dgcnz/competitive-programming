#include <bits/stdc++.h>

using namespace std;
using vi  = vector<int>;
using vvi = vector<vi>;

int main(void)
{
    int n, x;
    cin >> n >> x;

    vi h(n), s(n);
    for (auto &hi : h)
        cin >> hi;

    for (auto &si : s)
        cin >> si;

    vvi dp(n + 1, vi(x + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int c = 1; c <= x; ++c)
        {
            dp[i][c] = dp[i - 1][c];
            if (c - h[i - 1] >= 0)
                dp[i][c] = max(dp[i][c], dp[i - 1][c - h[i - 1]] + s[i - 1]);
        }
    }
    cout << dp[n][x] << endl;

    return 0;
}
