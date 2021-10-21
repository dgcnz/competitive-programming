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
    int    n;
    string s;
    cin >> n >> s;

    vector<vi> ans(26, vi(n + 1, 0));

    for (int c = 0; c < 26; ++c)
    {
        vector<vi> dp(n + 1, vi(n + 1, 0));
        for (int i = n - 1; i >= 0; --i)
            if ((s[i] - 'a') == c)
                dp[0][i] = 1 + dp[0][i + 1];
        for (int k = 1; k <= n; ++k)
        {
            for (int i = n - k; i >= 0; --i)
            {
                int ch_rem = n - i - 1;
                if (s[i] - 'a' == c)
                    dp[k][i] = dp[min(k, ch_rem)][i + 1] + 1;
                else
                    dp[k][i] = dp[min(k - 1, ch_rem)][i + 1] + 1;
                ans[c][k] = max(ans[c][k], dp[k][i]);
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int  m;
        char c;
        cin >> m >> c;
        cout << ans[c - 'a'][m] << endl;
    }
    return 0;
}
