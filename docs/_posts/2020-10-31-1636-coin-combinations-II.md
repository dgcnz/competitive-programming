---
layout: post
mathjax: true
title: 1636 Coin Combinations Ii
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
const int MOD = 1e9 + 7;
int solve(int n, int x, const vi &c)
{
    vvi dp(n + 1, vi(x + 1, 0));
    for (int i = 1; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int s = 1; s <= x; ++s)
        {
            int &ans = dp[i][s];
            ans = dp[i - 1][s];
            if (s - c[i - 1] >= 0)
                ans = (ans + dp[i][s - c[i - 1]]) % MOD;
        }
    }
    return dp[n][x];
}
int main(void)
{
    int n, x;
    cin >> n >> x;
    vi c(n);
    for (auto &ci : c)
        cin >> ci;
    sort(c.begin(), c.end());
    cout << solve(n, x, c) << endl;
    return 0;
}

{% endraw %}
```