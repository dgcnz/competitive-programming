---
layout: post
mathjax: true
title: 1192 Counting Rooms
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



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
using ii = pair<int, int>;
const int NMAX = 1e3 + 11;
int n, m;
bool wall[NMAX][NMAX];
vector<ii> directions = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
inline bool valid(int i, int j)
{
    return 0 <= i and i < n and 0 <= j and j < m and not wall[i][j];
}
vector<ii> neighbors(ii u)
{
    vector<ii> ans;
    auto [i, j] = u;
    for (auto [di, dj] : directions)
        if (valid(di + i, dj + j))
            ans.push_back({i + di, j + dj});
    return ans;
}
void dfs(ii u)
{
    auto [i, j] = u;
    wall[i][j] = true;
    for (auto v : neighbors(u))
        dfs(v);
}
int main(void)
{
    int ans = 0;
    char c;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> c;
            wall[i][j] = (c == '#');
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (not wall[i][j])
            {
                ans += 1;
                dfs({i, j});
            }
        }
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

