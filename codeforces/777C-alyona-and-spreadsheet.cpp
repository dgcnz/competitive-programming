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
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (auto &row : a)
        read(all(row));

    vector<vi>  dp(n, vi(m));
    vector<int> ans(n);
    fill(all(dp[0]), 0);
    ans[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            dp[i][j] = i;
            if (a[i][j] >= a[i - 1][j])
                dp[i][j] = dp[i - 1][j];
        }
        ans[i] = *min_element(all(dp[i]));
    }

    int k;
    cin >> k;
    while (k--)
    {
        int l, r;
        cin >> l >> r, l--, r--;

        cout << (l >= ans[r] ? "Yes" : "No") << endl;
    }

    return 0;
}
