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
using mint = modint998244353;

int solve(vector<string> board)
{
    int  h = board.size(), w = board[0].size();
    mint ans = 1;
    for (int r = 0; r < h; ++r)
    {
        int  len = min(w, r + 1);
        bool R = false, B = false, P = false;
        for (int c = 0; c < len; ++c)
        {
            R |= board[r - c][c] == 'R';
            B |= board[r - c][c] == 'B';
            P |= board[r - c][c] == '.';
        }
        if (R and B)
            ans = 0;
        else if (!R and !B)
            ans *= 2;
    }

    for (int c = 1; c < w; ++c)
    {
        int  len = min(h, w - c);
        bool R = false, B = false, P = false;
        for (int cc = c; cc < c + len; ++cc)
        {
            R |= board[h - 1 + c - cc][cc] == 'R';
            B |= board[h - 1 + c - cc][cc] == 'B';
            P |= board[h - 1 + c - cc][cc] == '.';
        }
        if (R and B)
            ans = 0;
        else if (!R and !B)
            ans *= 2;
    }
    return ans.val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    read(all(board));
    cout << solve(board) << endl;
    return 0;
}
