---
layout: post
mathjax: true
title: 118B Present From Lena
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
using ii = pair<int, int>;
vector<string> pat;
ii DUMMY = {-1, -1};
vector<ii> directions = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
vector<ii> neighbors(ii u)
{
    vector<ii> ans;
    for (auto [dr, dc] : directions)
        ans.emplace_back(u.first + dr, u.second + dc);
    return ans;
}
void bfs(ii start, int n)
{
    int level = n;
    set<ii> visited;
    queue<ii> frontier;
    frontier.push(start);
    frontier.push(DUMMY);
    visited.insert(start);
    while (not frontier.empty())
    {
        ii u = frontier.front();
        frontier.pop();
        if (u == DUMMY)
        {
            level--;
            if (level == -1)
                return;
            frontier.push({-1, -1});
            continue;
        }
        pat[u.first][u.second] = to_string(level)[0];
        for (auto v : neighbors(u))
        {
            if (visited.find(v) == visited.end())
            {
                visited.insert(v);
                frontier.push(v);
            }
        }
    }
}
int main(void)
{
    int n;
    cin >> n;
    pat.resize(2 * n + 1);
    for (auto &row : pat)
        row.resize(2 * n + 1, ' ');
    bfs({n, n}, n);
    for (int j = 0, p = pat.size(); j < p; ++j)
    {
        for (int i = 0, m = pat[j].size(); i < m; ++i)
        {
            cout << pat[j][i];
            if (pat[j][i] == '0' and i >= n)
                break;
            cout << ' ';
        }
        cout << endl;
    }
    return 0;
}

{% endraw %}
```