---
layout: post
mathjax: true
title: 1311A Add Odd Subtract Even
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
using ll = long long;
ll solve(ll a, ll b)
{
    ll diff = b - a;
    if (diff == 0)
        return 0;
    else if (diff > 0 and diff % 2 == 1)
        return 1;
    else if (diff < 0 and abs(diff) % 2 == 0)
        return 1;
    else
        return 2;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, ans;
        cin >> a >> b;
        ans = solve(a, b);
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```