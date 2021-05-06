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

int const AMAX   = 1e5 + 11;
int const TWOMAX = 20;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vi a(n);
    read(all(a));

    vi         next(AMAX);
    vector<vi> p(AMAX);
    for (int i = 2; i < AMAX; i++)
    {
        if (p[i].empty())
        {
            next[i] = n + 1;
            for (int j = i; j < AMAX; j += i)
                p[j].push_back(i);
        }
    }
    vector<vi> dp(TWOMAX, vi(n + 2, 0));
    dp[0][n + 1] = n + 1;
    for (int i = n; i > 0; i--)
    {
        dp[0][i] = dp[0][i + 1];
        for (int d : p[a[i - 1]])
        {
            dp[0][i] = min(dp[0][i], next[d]);
            next[d]  = i;
        }
    }
    for (int i = 1; i < TWOMAX; i++)
        for (int j = 1; j <= n + 1; j++)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
    while (q--)
    {
        int l, r, ans = 0;
        cin >> l >> r;
        for (int i = TWOMAX - 1; i >= 0; i--)
        {
            if (dp[i][l] <= r)
            {
                ans += (1 << i);
                l = dp[i][l];
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
