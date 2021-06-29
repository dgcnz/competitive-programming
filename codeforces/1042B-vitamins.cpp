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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    int const   INF = 1e9;
    vector<int> dp(8, INF);
    for (int i = 0; i < n; ++i)
    {
        int    c;
        string s;
        cin >> c >> s;
        int mask = 0;
        for (auto c : s)
        {
            if (c == 'A')
                mask |= 1;
            else if (c == 'B')
                mask |= 2;
            else
                mask |= 4;
        }
        dp[mask] = min(dp[mask], c);
        for (int mask2 = 0; mask2 < 8; ++mask2)
        {
            if (mask == mask2 or dp[mask2] == INF)
                continue;
            dp[mask | mask2] = min(dp[mask | mask2], dp[mask] + dp[mask2]);
        }
    }

    if (dp[7] == INF)
        cout << -1 << endl;
    else
        cout << dp[7] << endl;
    return 0;
}
