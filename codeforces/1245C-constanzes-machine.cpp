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

int solve(string s)
{
    for (auto c : s)
        if (c == 'm' or c == 'w')
            return 0;
    vector<int> blocks;
    int         cnt = 0;
    for (auto c : s)
    {
        if (c == 'n')
            cnt++;
        else if (cnt)
            blocks.push_back(cnt), cnt = 0;
    }
    if (cnt)
        blocks.push_back(cnt), cnt = 0;
    cnt = 0;
    for (auto c : s)
    {
        if (c == 'u')
            cnt++;
        else if (cnt)
            blocks.push_back(cnt), cnt = 0;
    }

    if (cnt)
        blocks.push_back(cnt), cnt = 0;

    int          n = s.size();
    vector<mint> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];

    mint ans = 1;
    for (auto b : blocks)
        ans *= dp[b];

    return ans.val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
