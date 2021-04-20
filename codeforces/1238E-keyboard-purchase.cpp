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

int solve(string s, int m)
{
    int        n = s.size();
    vector<vi> cnt(m, vi(m, 0));
    for (int i = 1; i < n; ++i)
        cnt[s[i - 1] - 'a'][s[i] - 'a']++, cnt[s[i] - 'a'][s[i - 1] - 'a']++;

    int const   INF = 1e8;
    vector<int> dp(1 << m, INF);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << m); ++mask)
    {
        for (int x = 0; x < m; ++x)
        {
            if (mask & (1 << x))
                continue;
            int posx = __builtin_popcount(mask), conx = 0;
            for (int y = 0; y < m; ++y)
            {
                if (mask & (1 << y))
                    conx += cnt[x][y] * posx;
                else if (y != x)
                    conx -= cnt[x][y] * posx;
            }
            int nmask = mask | (1 << x);
            dp[nmask] = min(dp[nmask], dp[mask] + conx);
        }
    }
    return dp[(1 << m) - 1];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    cout << solve(s, m) << endl;
    return 0;
}
