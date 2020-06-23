#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
using vll = vector<ll>;

int main(void)
{
    ll n, ans = INT_MIN;
    cin >> n;
    vll x(n), dp(n + 1, 0);

    for (auto &xi : x)
        cin >> xi;

    for (int i = 1; i <= n; ++i)
        dp[i] = max(dp[i - 1] + x[i - 1], x[i - 1]);

    for (int i = 1; i <= n; ++i)
        ans = max(dp[i], ans);

    cout << ans << endl;

    return 0;
}
