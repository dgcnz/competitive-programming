---
layout: post
mathjax: true
title: Abc175_D Moving Piece
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
using ll = long long;
int const NMAX = 3000 + 5;
ll const INF = 1e16;
ll n, m, k, dp[NMAX][NMAX][4], v[NMAX][NMAX];
ll solve(void)
{
    for (int c = 1; c <= m; ++c)
        fill(dp[0][c], dp[0][c] + 4, -INF);
    for (int r = 1; r <= n; ++r)
        fill(dp[r][0], dp[r][0] + 4, -INF);
    fill(dp[1][0], dp[1][0] + 4, 0);
    fill(dp[0][1], dp[0][1] + 4, 0);
    for (int r = 1; r <= n; ++r)
    {
        for (int c = 1; c <= m; ++c)
        {
            for (int cap = 0; cap <= 3; ++cap)
            {
                auto &ans = dp[r][c][cap];
                ans = max(dp[r - 1][c][3], dp[r][c - 1][cap]);
                if (cap > 0)
                {
                    ans = max({ans,
                               dp[r - 1][c][3] + v[r][c],
                               dp[r][c - 1][cap - 1] + v[r][c]});
                }
            }
        }
    }
    return *max_element(dp[n][m], dp[n][m] + 4);
}
int main(void)
{
    int ri, ci;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> ri >> ci;
        cin >> v[ri][ci];
    }
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```