#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vector<string> grid, int x, int y)
{
    int h = grid.size(), w = grid.back().size();

    int l = x, r = x, u = y, d = y;
    // left
    while (l > 0 and grid[l - 1][y] != '#')
        --l;
    while (r < h - 1 and grid[r + 1][y] != '#')
        ++r;
    // up
    while (u > 0 and grid[x][u - 1] != '#')
        --u;
    while (d < w - 1 and grid[x][d + 1] != '#')
        ++d;
    return r - l + 1 + d - u + 1 - 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int h, w, x, y;
    cin >> h >> w >> x >> y, x--, y--;
    vector<string> grid(h);
    for (auto &row : grid)
        cin >> row;
    cout << solve(grid, x, y) << endl;
    return 0;
}
