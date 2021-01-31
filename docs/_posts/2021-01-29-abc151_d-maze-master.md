---
layout: post
mathjax: true
title: abc151_d - Maze Master
problem_url: https://atcoder.jp/contests/abc151/tasks/abc151_d
tags: bfs, graphs
memory_complexity: O(n^2)
time_complexity: O(n^4)
---

The problem basically asks to ask of the diameter of the graph represented by
the board. We can get this number by launching a bfs from each cell to find
the furthest reachable cell.


{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using namespace std;
ll bfs(int i, int j, vector<string> &board)
{
    int h = (int)(board).size(), w = (int)(board[0]).size();
    vector<vector<bool>> visited(h, vector<bool>(w, 0));
    vector<vector<ll>> dist(h, vector<ll>(w, 1e9));
    queue<ii> frontier;
    frontier.emplace(i, j);
    visited[i][j] = true;
    dist[i][j] = 0;
    ll ans = 0;
    auto check = [&](int r, int c) {
        return board[r][c] != '#' and !visited[r][c];
    };
    auto visit = [&](int r, int c, ll d) {
        frontier.emplace(r, c);
        visited[r][c] = true;
        dist[r][c] = d;
        ans = max(ans, d);
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
    int h = (int)(board).size() - 2, w = (int)(board[0]).size() - 2;
    ll ans = 0;
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
    board[0] = string(w + 2, '#');
    board[h + 1] = string(w + 2, '#');
    for (int i = 1; i <= h; ++i)
    {
        cin >> board[i];
        board[i] = "#" + board[i] + "#";
    }
    cout << solve(board) << endl;
    return 0;
}

{% endraw %}
```
</details>

