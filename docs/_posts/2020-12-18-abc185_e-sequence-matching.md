---
layout: post
mathjax: true
title: abc185_e - Sequence Matching
problem_url: https://atcoder.jp/contests/abc185/tasks/abc185_e
tags: dp
memory_complexity: O(n^2)
time_complexity: O(n^2)
---

Lol, it was edit distance.
[Editorial](https://atcoder.jp/contests/abc185/editorial/418)


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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int solve(vi a, vi b)
{
    int const INF = 1e8;
    int n = (int)(a).size(), m = (int)(b).size();
    vector<vi> dp(n + 1, vi(m + 1, INF));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= m; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            auto &ans = dp[i][j];
            ans = min(ans, dp[i - 1][j] + 1);
            ans = min(ans, dp[i][j - 1] + 1);
            ans = min(ans, dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }
    return dp[n][m];
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    read_n(begin(a), n);
    read_n(begin(b), m);
    cout << solve(a, b) << endl;
    return 0;
}

{% endraw %}
```
</details>

