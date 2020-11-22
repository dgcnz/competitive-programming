---
layout: post
mathjax: true
title: 1618 Trailing Zeros
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
int solve(int n)
{
    if (n == 0)
        return 0;
    return n / 5 + solve(n / 5);
}
int main(void)
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}

{% endraw %}
```