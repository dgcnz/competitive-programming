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

vector<ii> solve(vector<string> board, bool c0, bool c1)
{
    int        n = board.size();
    vector<ii> ans;
    for (int i = 0; i < 3; ++i)
        if (board[n - i - 1][n + i - 3] - '0' != c0)
            ans.emplace_back(n - i - 1, n + i - 3);

    for (int i = 0; i < 2; ++i)
        if (board[n - i - 1][n + i - 2] - '0' != c1)
            ans.emplace_back(n - i - 1, n + i - 2);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> board(n);
        read(all(board));
        auto ans1 = solve(board, 0, 1);
        auto ans2 = solve(board, 1, 0);
        if (ans1.size() > ans2.size())
            ans1.swap(ans2);
        cout << ans1.size() << endl;
        for (auto [i, j] : ans1)
            cout << i + 1 << " " << j + 1 << endl;
    }
    return 0;
}
