#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/bfs>
#include <cplib/graph/gridgraph>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string reconstruct_path(ImplicitGridGraph<int> const      &g,
                        BFS<int, ImplicitGridGraph> const &bfs,
                        int                                v)
{
    auto path = bfs.reconstruct_path(v);
    if (path.size() >= 2)
    {
        string ans;
        for (int i = 1, k = path.size(); i < k; ++i)
        {
            auto u_rc = g.rid(path[i - 1]), v_rc = g.rid(path[i]);
            if (u_rc.first + 1 == v_rc.first)
                ans += 'D';
            else if (u_rc.first - 1 == v_rc.first)
                ans += 'U';
            else if (u_rc.second + 1 == v_rc.second)
                ans += 'R';
            else if (u_rc.second - 1 == v_rc.second)
                ans += 'L';
        }
        return ans;
    }
    else
        return "";
}

pair<bool, string> solve(vector<string> const &grid)
{
    auto [n, m] = grid_dimensions(grid);

    auto valid = [&grid](ii rc) { return grid[rc.first][rc.second] != '#'; };
    auto cost  = []([[maybe_unused]] ii, [[maybe_unused]] ii) { return 1; };
    ImplicitGridGraph<int> g(grid, valid, cost);
    vector<int>            monsters, exit;
    ii                     start;
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            if (grid[r][c] == 'M')
                monsters.push_back(g.id(r, c));
            if (grid[r][c] == 'A')
                start = {r, c};
            if ((r == 0 or r == n - 1 or c == 0 or c == m - 1) and
                grid[r][c] != '#')
                exit.push_back(g.id(r, c));
        }
    }

    BFS<int, ImplicitGridGraph> bfs(g);
    int const                   INF = 1e9;

    vector<int> distM(n * m, INF);
    for (auto u : monsters)
        distM[u] = 0;

    bfs(
        monsters,
        [&](int u, ii vw) { distM[vw.first] = distM[u] + vw.second; },
        [](int, ii) { return true; });

    vector<int> distA(n * m, INF);
    distA[g.id(start)] = 0;

    bfs(
        g.id(start),
        [&](int u, ii vw) { distA[vw.first] = distA[u] + vw.second; },
        [&](int u, ii vw) { return distA[u] + vw.second < distM[vw.first]; });

    for (auto v : exit)
        if (bfs.is_reachable(v))
            return {true, reconstruct_path(g, bfs, v)};

    return {false, ""};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    read(all(grid));

    auto [ok, ans] = solve(grid);
    if (ok)
    {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}
