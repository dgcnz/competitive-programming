---
layout: post
mathjax: true
title: 266A - Stones On Table
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
    int n, last, ans = 0;
    string s;
    cin >> n >> s;
    last = 0;
    for (auto c : s)
    {
        if (c == last)
            ++ans;
        last = c;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

