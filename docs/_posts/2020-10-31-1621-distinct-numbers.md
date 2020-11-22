---
layout: post
mathjax: true
title: 1621 Distinct Numbers
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
using vi = vector<int>;
int main(void)
{
    int n;
    cin >> n;
    vi x(n);
    for (auto &xi : x)
        cin >> xi;
    sort(x.begin(), x.end());
    cout << distance(x.begin(), unique(x.begin(), x.end())) << endl;
    return 0;
}

{% endraw %}
```