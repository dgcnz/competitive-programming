---
layout: post
mathjax: true
title: 1083 Missing Number
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