---
layout: post
mathjax: true
title: 716A - Crazy Computer
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
const int NMAX = 1e5 + 11;
int a[NMAX];
int main(void)
{
    int n, c, ans = 1;
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        ++ans;
        if (a[i] - a[i - 1] > c)
            ans = 1;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

