---
layout: post
mathjax: true
title: 1662 - Subarray Divisibility
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
int main(void)
{
    int n, ai;
    ll s = 0, ans = 0;
    map<ll, int> prefix_count;
    cin >> n;
    prefix_count[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        s = ((s + ai) % n + n) % n;
        ans += prefix_count[s];
        ++prefix_count[s];
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

