---
layout: post
mathjax: true
title: 1305C Kuroni Impossible Calculation
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
int n, m;
int a[200010];
ll solve(void)
{
    ll ans = 1;
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            ans = (ans * (a[i] - a[j]) % m) % m;
    }
    return ans;
}
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n <= m)
        cout << solve() << endl;
    else
        cout << 0 << endl;
    return 0;
}

{% endraw %}
```
</details>

