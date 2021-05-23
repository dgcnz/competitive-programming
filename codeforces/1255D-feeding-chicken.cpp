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

int ceil(int a, int b) { return (a + b - 1) / b; }

char ch(int n)
{
    if (n < 26)
        return n + 'a';
    else if (n < 52)
        return n - 26 + 'A';
    else
        return n - 52 + '0';
}

vector<string> solve(vector<string> board, int k)
{
    int n = board.size(), m = board[0].size();

    int chicken = 0, total_rice = 0, rice = 0;
    for (int i = 0; i < n; ++i)
        total_rice += count(all(board[i]), 'R');

    vector<string> ans(n, string(m, ' '));
    auto           symbol = [&](int i, int j) {
        if (board[i][j] == 'R')
        {
            rice++;
            int limit = chicken < (total_rice % k) ? ceil(total_rice, k)
                                                             : total_rice / k;
            if (rice > limit)
                chicken++, rice = 1;
        }
        return ch(chicken);
    };
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
            for (int j = 0; j < m; ++j)
                ans[i][j] = symbol(i, j);
        else
            for (int j = m - 1; j >= 0; --j)
                ans[i][j] = symbol(i, j);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> board(n);
        for (int i = 0; i < n; ++i)
            cin >> board[i];

        auto colored = solve(board, k);
        for (int i = 0; i < n; ++i)
            cout << colored[i] << endl;
    }
    return 0;
}
