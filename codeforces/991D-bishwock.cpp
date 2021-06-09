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

int solve(vector<string> board)
{
    int        n = board[0].size();
    vector<vi> dp(n + 2, vi(5, 0));

    auto check = [&](vector<ii> pos) {
        for (auto [i, j] : pos)
            if (board[i][j] == 'X')
                return false;
        return true;
    };

    auto valid = [&](int i, int t) {
        if (t == 0)
            return true;
        else if (t == 1)
            return check({{0, i}, {1, i}, {0, i + 1}});
        else if (t == 2)
            return check({{0, i}, {0, i + 1}, {1, i + 1}});
        else if (t == 3)
            return check({{1, i}, {0, i + 1}, {1, i + 1}});
        else
            return check({{0, i}, {1, i}, {1, i + 1}});
    };

    for (int i = n - 2; i >= 0; --i)
    {
        dp[i][0] = *max_element(all(dp[i + 1]));
        if (valid(i, 1))
            dp[i][1] = 1 + max(dp[i + 1][3], dp[i + 1][0]);
        if (valid(i, 2))
            dp[i][2] = 1 + dp[i + 1][0];
        if (valid(i, 3))
            dp[i][3] = 1 + dp[i + 1][0];
        if (valid(i, 4))
            dp[i][4] = 1 + max(dp[i + 1][2], dp[i + 1][0]);
    }
    return *max_element(all(dp[0]));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    vector<string> board(2);
    cin >> board[0] >> board[1];
    cout << solve(board) << endl;
    return 0;
}
