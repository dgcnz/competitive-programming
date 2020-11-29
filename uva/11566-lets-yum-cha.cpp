#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using predicate = function<bool(int)>;

int const KMAX = 100 + 2;
int const NMAX = 10 + 2;
int const XMAX = 100 + 2;

int n, x, t, k, p[2 * KMAX + 1], f[2 * KMAX + 1];
int dp[2 * KMAX][2 * (NMAX + 1)][NMAX * XMAX];

int bs(int l, int r, predicate p)
{
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        if (p(m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

inline int ceil(int a, int b) { return (a + b - 1) / b; }
inline int cost(int y) { return ceil(11 * (y + n * t), 10); }

double solve(void)
{
    memset(dp, 0, sizeof dp); // check later
    n += 1;
    int max_money = bs(0, n * x, [](int y) { return cost(y) <= (n * x); });

    for (int i = 1; i <= 2 * k + 1; ++i)
    {
        for (int q = 0; q <= (2 * n); ++q)
        {
            for (int m = 0; m <= max_money; ++m)
            {
                auto &ans     = dp[i][q][m];
                int   new_rem = m - p[i - 1];

                ans = max(ans, dp[i - 1][q][m]); // not choosing anything
                if (new_rem >= 0 and q > 0)
                    ans = max(ans, dp[i - 1][q - 1][new_rem] + f[i - 1]);
            }
        }
    }
    int ans = 0;
    for (int q = 0; q <= (2 * n); ++q)
        ans = max(ans, dp[2 * k + 1][q][max_money]);
    return (ans / double(n));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    while (cin >> n >> x >> t >> k and n != 0)
    {
        memset(p, 0, sizeof p);
        memset(f, 0, sizeof f);
        for (int i = 0; i < k; ++i)
        {
            int fj;
            cin >> p[2 * i];
            p[2 * i + 1] = p[2 * i];
            f[2 * i]     = 0;
            for (int j = 0; j <= n; ++j)
                cin >> fj, f[2 * i] += fj;
            f[2 * i + 1] = f[2 * i];
        }
        cout << fixed << setprecision(2) << solve() << endl;
    }
    return 0;
}
