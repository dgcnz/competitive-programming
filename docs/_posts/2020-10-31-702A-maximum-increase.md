---
layout: post
mathjax: true
title: 702A Maximum Increase
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

```cpp
{% raw %}
using namespace std;
int n;
int a[100010];
int solve(void)
{
    int ans = 1;
    int cur = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i - 1])
            ++cur;
        else
            cur = 1;
        ans = max(ans, cur);
    }
    return ans;
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```