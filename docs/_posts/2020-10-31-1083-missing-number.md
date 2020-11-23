---
layout: post
mathjax: true
title: 1083 Missing Number
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
    int n, x;
    cin >> n;
    vector<bool> is_present(n + 1, false);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> x;
        is_present[x] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (not is_present[i])
            cout << i << endl;
    return 0;
}

{% endraw %}
```
</details>

