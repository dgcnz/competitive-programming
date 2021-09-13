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

int solve(vector<string> table, ii src)
{
    int n = table.size(), m = table.back().size();

    auto is_land = [&](ii u)
    { return table[u.first][u.second] == table[src.first][src.second]; };

    queue<ii>            frontier;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<ii>           dir = {{0, -1}, {0, +1}, {-1, 0}, {+1, 0}};

    auto bfs = [&](ii s)
    {
        int cnt = 0;
        frontier.push(s);
        vis[s.first][s.second] = true;
        while (not frontier.empty())
        {
            auto u = frontier.front();
            frontier.pop();

            cnt += 1;

            for (auto [dr, dc] : dir)
            {
                int vr = u.first + dr, vc = (u.second + m + dc) % m;
                if (0 <= vr and vr < n and not vis[vr][vc] and
                    is_land({vr, vc}))
                {
                    vis[vr][vc] = true;
                    frontier.push({vr, vc});
                }
            }
        }
        return cnt;
    };
    bfs(src);

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (not vis[i][j] and is_land({i, j}))
            {
                ans = max(ans, bfs({i, j}));
            }
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;

    while (cin >> n >> m)
    {
        vector<string> table(n);
        read(all(table));
        ii src;
        cin >> src.first >> src.second;
        cout << solve(table, src) << endl;
    }

    return 0;
}
