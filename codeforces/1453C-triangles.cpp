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

vi solve(vector<string> board)
{
    int n = board.size();

    vector<int> down(10, -1), up(10, -1);
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < n; ++j)
        {
            int d = board[i][j] - '0';
            if (down[d] == -1)
                down[d] = i;
            up[d] = i;
        }
    }

    vector<int> ans(10, 0);
    for (int i = 0; i < n; ++i)
    {
        vector<int> leftmost(10, -1), rightmost(10, -1);
        for (int j = n - 1; j >= 0; --j)
            leftmost[board[i][j] - '0'] = j;
        for (int j = 0; j < n; ++j)
            rightmost[board[i][j] - '0'] = j;
        for (int d = 0; d < 10; ++d)
        {
            if (leftmost[d] == -1)
                continue;
            if (leftmost[d] != rightmost[d])
            {
                int base  = rightmost[d] - leftmost[d];
                int hup   = up[d] < i ? i - up[d] : 0;
                int hdown = down[d] > i ? down[d] - i : 0;
                ans[d]    = max(ans[d], base * max(hup, hdown));
            }
            int base = max(rightmost[d], n - leftmost[d] - 1);
            if (up[d] < i)
                ans[d] = max(ans[d], (i - up[d]) * base);
            if (down[d] > i)
                ans[d] = max(ans[d], (down[d] - i) * base);
        }
    }
    return ans;
}

vector<string> transpose(vector<string> board)
{
    int            n = board.size();
    vector<string> ans(n, string(n, '.'));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans[j][i] = board[i][j];
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
        auto ans1 = solve(board);
        auto ans2 = solve(transpose(board));
        for (int i = 0; i < 10; ++i)
            cout << max(ans1[i], ans2[i]) << " ";
        cout << endl;
    }
    return 0;
}
