---
layout: post
mathjax: true
title: 1350B Orac And Models
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
const int NMAX = 1e5 + 11;
int n, s[NMAX];
int solve(void)
{
    vi dp(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 2; j * i <= n; ++j)
            if (s[i] < s[i * j])
                dp[i * j] = max(dp[i * j], dp[i] + 1);
    }
    return *max_element(dp.begin(), dp.end());
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> s[i];
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```