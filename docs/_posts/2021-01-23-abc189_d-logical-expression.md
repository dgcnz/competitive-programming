---
layout: post
mathjax: true
title: abc189_d - Logical Expression
problem_url: https://atcoder.jp/contests/abc189/tasks/abc189_d
tags: dp
memory_complexity: O(n)
time_complexity: O(n)
---

Let's define the following dps:

$dp_1(i)$ : Number of ways for the expression $x_0,...x_i$ to be true with
the given logical operators up to the $i$th.

$dp_0(i)$ : Number of ways for the expression $x_0,...x_i$ to be false with
the given logical operators up to the $i$th.

In $dp_1$:

For the case where the $i$th logical operator, $op$, $x_{i-1} op x_i$, is an
`AND`, we need the expression $x_0,...x_{i-1}$ to yield true.

For the case where the $i$th logical operator, $op$, $x_{i-1} op x_i$, is an
`OR`, the expression $x_0,...x_{i-1}$ can yield true (in which case $x_i$ can
be either true or false) or false (in which case $x_i$ must be true).

One can similarly define $dp_0$.


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
using vll = vector<ll>;
ll solve(vi a)
{
    int n = (int)(a).size();
    vector<vll> dp(n + 1, vll(2, 0));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i - 1])
        {
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = 2 * dp[i - 1][0] + dp[i - 1][1];
        }
        else
        {
            dp[i][1] = dp[i - 1][0] + 2 * dp[i - 1][1];
            dp[i][0] = dp[i - 1][0];
        }
    }
    return dp[n][1];
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &ai : a)
    {
        string s;
        cin >> s;
        ai = s == "AND";
    }
    cout << solve(a) << endl;
    return 0;
}

{% endraw %}
```
</details>

