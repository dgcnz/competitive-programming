---
layout: post
mathjax: true
title: Abc172_B Minor Change
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