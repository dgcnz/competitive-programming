---
layout: post
mathjax: true
title: 1392A Omkar Password
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
    int t, n, ai;
    cin >> t;
    while (t--)
    {
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; ++i)
        {
            cin >> ai;
            s.insert(ai);
        }
        if (s.size() == 1)
            cout << n << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

