---
layout: post
mathjax: true
title: 1643 Maximum Subarray Sum
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
using ll = long long;
using vll = vector<ll>;
int main(void)
{
    ll n, ans = INT_MIN;
    cin >> n;
    vll x(n), dp(n + 1, 0);
    for (auto &xi : x)
        cin >> xi;
    for (int i = 1; i <= n; ++i)
        dp[i] = max(dp[i - 1] + x[i - 1], x[i - 1]);
    for (int i = 1; i <= n; ++i)
        ans = max(dp[i], ans);
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

