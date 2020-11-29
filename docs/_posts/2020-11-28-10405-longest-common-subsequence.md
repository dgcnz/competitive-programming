---
layout: post
mathjax: true
title: 10405 - Longest Common Subsequence
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
using vi = vector<int>;
int solve(string s, string t)
{
    int n = (int)s.size(), m = (int)t.size();
    vector<vi> dp(n + 1, vi(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            auto &ans = dp[i][j];
            ans = max(ans, dp[i - 1][j]);
            ans = max(ans, dp[i][j - 1]);
            if (s[i - 1] == t[j - 1])
                ans = max(ans, dp[i - 1][j - 1] + 1);
        }
    }
    return dp[n][m];
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s, t;
    while (getline(cin, s) and getline(cin, t))
    {
        cout << solve(s, t) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

