---
layout: post
mathjax: true
title: Abc175 Rainy Season
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

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