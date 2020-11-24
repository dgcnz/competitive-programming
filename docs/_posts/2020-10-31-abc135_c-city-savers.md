---
layout: post
mathjax: true
title: abc135_c - City Savers
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
using vi = vector<int>;
using ll = long long;
int main(void)
{
    int n;
    ll cur_killed, total_killed;
    vi a, b;
    cin >> n;
    a.resize(n + 1), b.resize(n);
    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;
    total_killed = 0;
    for (int i = 0; i < n; ++i)
    {
        cur_killed = min(b[i], a[i] + a[i + 1]);
        total_killed += cur_killed;
        a[i + 1] -= max(0LL, cur_killed - a[i]);
    }
    cout << total_killed << endl;
    return 0;
}

{% endraw %}
```
</details>

