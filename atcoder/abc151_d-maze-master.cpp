/** @file
 * @date                2021-01-29
 * @url                 https://atcoder.jp/contests/abc151/tasks/abc151_d
 * @tags                bfs, graphs
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         20
 * @time_complexity     O(n^4)
 * @memory_complexity   O(n^2)
 * @idea
 * The problem basically asks to ask of the diameter of the graph represented by
 * the board. We can get this number by launching a bfs from each cell to find
 * the furthest reachable cell.
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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using namespace std;

ll bfs(int i, int j, vector<string> &board)
{
    int h = isz(board), w = isz(board[0]);

    vector<vector<bool>> visited(h, vector<bool>(w, 0));
    vector<vector<ll>>   dist(h, vector<ll>(w, 1e9));

    queue<ii> frontier;
    frontier.emplace(i, j);
    visited[i][j] = true;
    dist[i][j]    = 0;
    ll ans        = 0;

    auto check = [&](int r, int c) {
        return board[r][c] != '#' and !visited[r][c];
    };
    auto visit = [&](int r, int c, ll d) {
        frontier.emplace(r, c);
        visited[r][c] = true;
        dist[r][c]    = d;
        ans           = max(ans, d);
    };

    while (not frontier.empty())
    {
        auto [r, c] = frontier.front();
        frontier.pop();

        if (check(r, c + 1))
            visit(r, c + 1, dist[r][c] + 1);
        if (check(r + 1, c))
            visit(r + 1, c, dist[r][c] + 1);
        if (check(r, c - 1))
            visit(r, c - 1, dist[r][c] + 1);
        if (check(r - 1, c))
            visit(r - 1, c, dist[r][c] + 1);
    }
    return ans;
}

ll solve(vector<string> board)
{
    int h = isz(board) - 2, w = isz(board[0]) - 2;
    ll  ans = 0;
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            if (board[i][j] != '#')
                ans = max(ans, bfs(i, j, board));

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int h, w;
    cin >> h >> w;

    vector<string> board(h + 2);
    board[0]     = string(w + 2, '#');
    board[h + 1] = string(w + 2, '#');
    for (int i = 1; i <= h; ++i)
    {
        cin >> board[i];
        board[i] = "#" + board[i] + "#";
    }

    cout << solve(board) << endl;
    return 0;
}
