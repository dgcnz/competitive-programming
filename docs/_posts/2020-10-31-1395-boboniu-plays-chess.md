---
layout: post
mathjax: true
title: 1395 Boboniu Plays Chess
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
using vii = vector<ii>;
int const NMAX = 100 + 11;
int n, m, row_cnt[NMAX], r0, c0;
bool visited[NMAX][NMAX];
vii ans;
void solve(void)
{
    int c;
    c = c0;
    if (r0 == 0)
    {
        ans.pop_back();
        row_cnt[r0]++;
    }
    for (int r = 0; r < n; ++r)
    {
        visited[r][c] = true;
        row_cnt[r]--;
        ans.emplace_back(r, c);
        while (row_cnt[r] > 0)
        {
            auto it = find(visited[r], visited[r] + m, false);
            *it = true;
            ans.emplace_back(r, distance(visited[r], it));
            row_cnt[r]--;
        }
        c = ans.back().second;
        if (r + 1 == r0 and c == c0)
        {
            int sz = ans.size();
            swap(ans[sz - 1], ans[sz - 2]);
            c = ans.back().second;
        }
    }
}
int main(void)
{
    cin >> n >> m;
    cin >> r0 >> c0;
    r0--, c0--;
    fill(row_cnt, row_cnt + n, m);
    row_cnt[r0]--;
    visited[r0][c0] = true;
    ans.push_back({r0, c0});
    solve();
    for (auto [r, c] : ans)
        cout << r + 1 << " " << c + 1 << endl;
    cout << endl;
    return 0;
}

{% endraw %}
```