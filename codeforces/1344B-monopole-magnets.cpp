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

int solve(vector<string> grid)
{
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>>  brow(n), bcol(m);
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    function<int(int, int)> dfs = [&](int r, int c) {
        if (!(0 <= r and r < n and 0 <= c and c < m) or grid[r][c] == '.' or
            vis[r][c])
            return 0;
        vis[r][c] = true;
        return 1 + dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) +
               dfs(r, c - 1);
    };

    int ans = 0;
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            if (grid[r][c] == '.')
                continue;
            brow[r].push_back(c);
            bcol[c].push_back(r);
            if (!vis[r][c])
                ans += (dfs(r, c) > 0);
        }
    }

    int empty_rows = 0, empty_cols = 0;
    for (int r = 0; r < n; ++r)
    {
        if (brow[r].empty())
            empty_rows++;
        else
        {
            int prev = brow[r].front() - 1;
            for (auto c : brow[r])
            {
                if (c - prev > 1)
                    return -1;
                prev = c;
            }
        }
    }

    for (int c = 0; c < m; ++c)
    {
        if (bcol[c].empty())
            empty_cols++;
        else
        {
            int prev = bcol[c].front() - 1;
            for (auto r : bcol[c])
            {
                if (r - prev > 1)
                    return -1;
                prev = r;
            }
        }
    }

    if ((empty_rows > 0) != (empty_cols > 0))
        return -1;

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    read(all(grid));
    cout << solve(grid) << endl;
    return 0;
}
