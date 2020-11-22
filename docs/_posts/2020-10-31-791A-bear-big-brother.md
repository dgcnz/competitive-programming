---
layout: post
mathjax: true
title: 791A Bear Big Brother
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
    int a, b, ans = 0;
    cin >> a >> b;
    while (a <= b)
    {
        a *= 3;
        b *= 2;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```