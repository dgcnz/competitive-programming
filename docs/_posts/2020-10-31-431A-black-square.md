---
layout: post
mathjax: true
title: 431A Black Square
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
int main(void)
{
    int ans = 0;
    vi cost(4, 0);
    string s;
    for (auto &x : cost)
        cin >> x;
    cin >> s;
    for (auto c : s)
        ans += cost[c - '0' - 1];
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

