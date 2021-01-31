---
layout: post
mathjax: true
title: 1630 - Tasks Deadlines
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
using pll = pair<ll, ll>;
using vpll = vector<pll>;
int main(void)
{
    ll n;
    cin >> n;
    vpll tasks(n);
    for (auto &[a, d] : tasks)
        cin >> a >> d;
    sort(tasks.begin(), tasks.end());
    ll tim = 0, reward = 0;
    for (auto [a, d] : tasks)
    {
        tim += a;
        reward += d - tim;
    }
    cout << reward << endl;
    return 0;
}

{% endraw %}
```
</details>

