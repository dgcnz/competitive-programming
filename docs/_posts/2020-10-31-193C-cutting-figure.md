---
layout: post
title: 193C Cutting Figure
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int const NMAX = 50 + 11;
int n, m;
bool painted[NMAX][NMAX];
vector<ii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
inline bool valid(int r, int c)
{
    return 0 <= r and r < n and 0 <= c and c < m;
}
vector<ii> get_neighbors(int r, int c)
{
    vector<ii> ans;
    for (auto [dr, dc] : directions)
        if (valid(r + dr, c + dc) and painted[r + dr][c + dc])
            ans.emplace_back(r + dr, c + dc);
    return ans;
}
bool bfs(int r, int c, vector<ii> targets)
{
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    queue<ii> frontier;
    visited[r][c] = true;
    frontier.emplace(r, c);
    while (not frontier.empty())
    {
        auto [r, c] = frontier.front();
        frontier.pop();
        if (auto it = find(targets.begin(), targets.end(), make_pair(r, c)); it != targets.end())
        {
            targets.erase(it);
            if ((int)targets.size() == 0)
            {
                return true;
            }
        }
        for (auto [rr, cc] : get_neighbors(r, c))
        {
            if (not visited[rr][cc])
            {
                frontier.emplace(rr, cc);
                visited[rr][cc] = true;
            }
        }
    }
    return false;
}
int main(void)
{
    cin >> n >> m;
    int asz = 0;
    char ch;
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
            cin >> ch, painted[r][c] = (ch == '#'), asz += painted[r][c];
    if (asz <= 2)
        cout << -1 << endl;
    else
    {
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < m; ++c)
            {
                if (not painted[r][c])
                    continue;
                auto neighbors = get_neighbors(r, c);
                auto [rr, cc] = neighbors.back();
                neighbors.pop_back();
                painted[r][c] = false;
                if ((int)neighbors.size() == 0 or not bfs(rr, cc, neighbors))
                {
                    cout << 1 << endl;
                    return 0;
                }
                painted[r][c] = true;
            }
        }
        cout << 2 << endl;
    }
    return 0;
}

{% endraw %}
```
