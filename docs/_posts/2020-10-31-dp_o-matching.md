---
layout: post
mathjax: true
title: dp_o - Matching
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
const int NMAX = 21 + 2;
const int MOD = 1e9 + 7;
int n, a[NMAX][NMAX];
int solve(void)
{
    vector<vi> dp(1LL << n, vi(n + 1, 0));
    dp[0][0] = 1;
    for (int mask = 1; mask < (1LL << n); ++mask)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (__builtin_popcount(mask) != i)
                continue;
            for (int j = 1; j <= n; ++j)
            {
                if (((mask >> (j - 1)) & 1LL) and a[i - 1][j - 1])
                {
                    dp[mask][i] =
                        (dp[mask][i] + dp[mask ^ (1LL << (j - 1))][i - 1]) %
                        MOD;
                }
            }
        }
    }
    return dp[(1 << n) - 1][n];
}
int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```
</details>

