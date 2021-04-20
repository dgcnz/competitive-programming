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

int const            MMAX = 2e5 + 3;
vector<vector<mint>> ans(10, vector<mint>(MMAX, 0));
vector<vector<bool>> vis(10, vector<bool>(MMAX, 0));

mint dp(int d, int k)
{
    if (vis[d][k])
        return ans[d][k];
    vis[d][k] = true;
    if (d == 9)
        return (ans[d][k] = dp(0, k - 1) + dp(1, k - 1));
    else
        return (ans[d][k] = dp(d + 1, k - 1));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    for (int d = 0; d <= 9; ++d)
        ans[d][0] = 1, vis[d][0] = true;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s   = to_string(n);
        mint   len = 0;
        for (auto c : s)
            len += dp(c - '0', m);
        cout << len.val() << endl;
    }
    return 0;
}
