---
layout: post
mathjax: true
title: 1365D Solve The Maze
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vb>;
const int NMAX = 55;
int n, m;
vector<ii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char maze[NMAX][NMAX];
inline bool in_bounds(int r, int c)
{
    return (0 <= r and r < n) and (0 <= c and c < m);
}
vector<ii> neighbors(int r0, int c0)
{
    vector<ii> ans;
    for (auto [dr, dc] : directions)
        if (in_bounds(r0 + dr, c0 + dc))
            ans.push_back({r0 + dr, c0 + dc});
    return ans;
}
bool solve(void)
{
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            if (maze[row][col] == 'B')
            {
                for (auto [nr, nc] : neighbors(row, col))
                    if (maze[nr][nc] == '.')
                        maze[nr][nc] = '#';
            }
        }
    }
    queue<ii> frontier;
    vvb visited = vvb(n, vb(m, false));
    if (maze[n - 1][m - 1] == '.')
    {
        visited[n - 1][m - 1] = true;
        frontier.push({n - 1, m - 1});
    }
    while (not frontier.empty())
    {
        auto [r, c] = frontier.front();
        frontier.pop();
        for (auto [nr, nc] : neighbors(r, c))
        {
            if (maze[nr][nc] != '#' and not visited[nr][nc])
            {
                frontier.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    for (int row = 0; row < n; ++row)
        for (int col = 0; col < m; ++col)
            if ((maze[row][col] == 'G' and not visited[row][col]) or
                (maze[row][col] == 'B' and visited[row][col]))
                return false;
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int row = 0; row < n; ++row)
            cin >> maze[row];
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}

{% endraw %}
```