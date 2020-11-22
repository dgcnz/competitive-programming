---
layout: post
mathjax: true
title: 1744 Rectangle Cutting
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
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 1e9;
int main(void)
{
    int a, b;
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    vvi dp(a + 1, vi(b + 1, 0));
    for (int r = 1; r <= a; ++r)
    {
        for (int c = 1; c <= b; ++c)
        {
            if (r == c)
                continue;
            int &ans = dp[r][c] = INF;
            for (int k = 1; k < r; ++k)
                ans = min(ans, dp[k][c] + dp[r - k][c] + 1);
            for (int k = 1; k < c; ++k)
                ans = min(ans, dp[r][k] + dp[r][c - k] + 1);
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}

{% endraw %}
```