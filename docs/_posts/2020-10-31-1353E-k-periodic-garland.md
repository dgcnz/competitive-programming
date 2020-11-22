---
layout: post
mathjax: true
title: 1353E K Periodic Garland
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
const int NMAX = 1e6 + 11;
int n, k, a[NMAX];
int solve(void)
{
    int sum = accumulate(a, a + n, 0);
    int ans = sum;
    for (int i = 0; i < k; ++i)
    {
        vi dp(n / k + 1, 0);
        vi acc(n / k + 1, 0);
        int m = 0;
        for (int j = i; j < n; j += k, ++m)
        {
            dp[m] = (a[j] != 1);
            if (m > 0)
                dp[m] += min(dp[m - 1], acc[m - 1]);
            acc[m] = a[j] + (m == 0 ? 0 : acc[m - 1]);
        }
        for (int j = 0; j < m; ++j)
            ans = min(ans, dp[j] + sum - acc[j]);
    }
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> n >> k >> s;
        for (int i = 0; i < n; ++i)
            a[i] = s[i] - '0';
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```