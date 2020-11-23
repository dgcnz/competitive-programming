---
layout: post
mathjax: true
title: 1321A Contest Robots
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
bool r[110];
bool b[110];
int n;
int main(void)
{
    int win = 0, loss = 0, ans;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> r[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
    {
        if (r[i] and not b[i])
            ++win;
        if (not r[i] and b[i])
            ++loss;
    }
    if (win > 0)
        ans = (int)ceil((loss + 1.0) / win);
    else
        ans = -1;
    cout << ans << endl;
}

{% endraw %}
```
</details>

