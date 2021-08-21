#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint1000000007;

int solve(vector<vi> a, vi p, int l)
{
    int                  k = a.size();
    int                  n = p.size();
    vector<vector<mint>> dp(n + 1, vector<mint>(k, 0));
    fill(all(dp[n]), mint(1));
    partial_sum(all(dp[n]), begin(dp[n]));

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < k; ++j)
        {
            auto itl = lower_bound(all(a[j]), p[i] - l);
            auto itr = upper_bound(all(a[j]), p[i] + l);
            if (itl == a[j].end() or itr == a[j].begin())
                continue;
            itr--;
            int ixl = distance(a[j].begin(), itl);
            int ixr = distance(a[j].begin(), itr);
            dp[i][j] =
                dp[i + 1][ixr] - (ixl == 0 ? mint(0) : dp[i + 1][ixl - 1]);
        }
        partial_sum(all(dp[i]), begin(dp[i]));
    }

    return dp[0].back().val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int k, l;
    cin >> k >> l;

    vector<vi> a(k, vi(k));
    for (auto &row : a)
        read(all(row));

    int n;
    cin >> n;
    vi p(n - 1);
    read(all(p));
    cout << solve(a, p, l) << endl;

    return 0;
}
