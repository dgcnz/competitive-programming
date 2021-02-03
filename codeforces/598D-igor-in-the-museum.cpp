/** @file
 * @date                2021-02-01
 * @url                 https://codeforces.com/problemset/problem/598/D
 * @tags                graphs, dfs
 * @status              AC
 * @score               1
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         30
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * For each connected component, count its borders.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll    = long long;
using ii    = pair<int, int>;
using vi    = vector<int>;
using Graph = vector<vi>;

tuple<Graph, function<int(int, int)>, function<ii(int)>> grid_graph(int n,
                                                                    int m)
{
    /*
     * Returns grid graph given dimensions.
     */

    Graph g(n * m);
    auto  id      = [m](int i, int j) { return i * m + j; };
    auto  rid     = [m](int u) { return ii{u / m, u % m}; };
    auto add_edge = [&](int u, int v) { g[u].push_back(v), g[v].push_back(u); };

    for (int i = 1; i < n; ++i)
        add_edge(id(i, 0), id(i - 1, 0));

    for (int j = 1; j < m; ++j)
        add_edge(id(0, j), id(0, j - 1));

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            add_edge(id(i, j), id(i, j - 1)), add_edge(id(i, j), id(i - 1, j));

    return {g, id, rid};
}

vector<vi> preprocess(vector<string> &board)
{
    int n = board.size(), m = board.front().size();
    auto [g, id, rid] = grid_graph(n, m);

    vector<vi> ans(n, vi(m, 0));

    vector<bool> vis(n * m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int         cnt = 0, a = id(i, j);
            vector<int> component;

            function<void(int)> dfs = [&](int u) {
                vis[u] = true;
                for (auto v : g[u])
                {
                    auto [ii, jj] = rid(v);
                    if (board[ii][jj] == '*')
                        cnt++;
                    if (vis[v])
                        continue;
                    if (board[ii][jj] == '.')
                        dfs(v);
                }
                component.push_back(u);
            };
            if (not vis[a] and board[i][j] == '.')
            {
                dfs(a);
                for (auto u : component)
                {
                    auto [ii, jj] = rid(u);
                    ans[ii][jj]   = cnt;
                }
            }
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> board(n);
    for (auto &row : board)
        cin >> row;

    auto ans = preprocess(board);
    while (k--)
    {
        int i, j;
        cin >> i >> j, i--, j--;
        cout << ans[i][j] << endl;
    }

    return 0;
}
