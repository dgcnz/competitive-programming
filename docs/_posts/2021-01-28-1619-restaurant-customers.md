---
layout: post
mathjax: true
title: 1619 - Restaurant Customers
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
using ii = pair<int, int>;
using vii = vector<ii>;
int main(void)
{
    int n, a, b, people = 0, ans = 0;
    cin >> n;
    vii events(2 * n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        events[2 * i] = {a, +1};
        events[2 * i + 1] = {b, -1};
    }
    sort(events.begin(), events.end());
    for (auto [t, s] : events)
    {
        people += s;
        ans = max(ans, people);
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

