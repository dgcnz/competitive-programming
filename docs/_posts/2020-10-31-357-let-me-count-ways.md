---
layout: post
mathjax: true
title: 357 Let Me Count Ways
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
const int NMAX = 3e4 + 11;
int n, coins[5] = {1, 5, 10, 25, 50};
ll dp[NMAX];
ll solve(void)
{
    dp[0] = 1;
    for (int i = 0; i < 5; ++i)
        for (int j = coins[i]; j <= n; ++j)
            dp[j] += dp[j - coins[i]];
    return dp[n];
}
int main(void)
{
    ll m;
    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        m = solve();
        if (m == 1)
            cout << "There is only 1 way to produce ";
        else
            cout << "There are " << m << " ways to produce ";
        cout << n << " cents change." << endl;
    }
    return 0;
}

{% endraw %}
```