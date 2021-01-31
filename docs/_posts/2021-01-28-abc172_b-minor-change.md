---
layout: post
mathjax: true
title: abc172_b - Minor Change
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
int main(void)
{
    int ans = 0;
    string s, t;
    cin >> s >> t;
    for (int i = 0, n = s.size(); i < n; ++i)
    {
        ans += (s[i] != t[i]);
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

