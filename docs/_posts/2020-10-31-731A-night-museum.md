---
layout: post
mathjax: true
title: 731A Night Museum
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
inline int ord(char c) { return c - 'a'; }
int main(void)
{
    int ans = 0, last = 0;
    string s;
    cin >> s;
    for (auto c : s)
    {
        ans += min(26 - abs(ord(c) - last), abs(ord(c) - last));
        last = ord(c);
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```