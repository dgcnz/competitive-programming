---
layout: post
mathjax: true
title: abc175 - Rainy Season
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
    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    for (auto c : s)
    {
        if (c == 'R')
            ++cnt;
        else
        {
            ans = max(cnt, ans);
            cnt = 0;
        }
    }
    ans = max(cnt, ans);
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

