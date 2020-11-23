---
layout: post
mathjax: true
title: 427A Police Recruits
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

```cpp
{% raw %}
using namespace std;
int main(void)
{
    int n, police = 0, ans = 0, event;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> event;
        if (event > 0)
            police += event;
        else if (event == -1 and police > 0)
            --police;
        else
            ++ans;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```