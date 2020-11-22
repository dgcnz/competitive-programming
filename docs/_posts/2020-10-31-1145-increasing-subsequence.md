---
layout: post
mathjax: true
title: 1145 Increasing Subsequence
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
    int n, x;
    vi dp;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it != dp.end())
            *it = x;
        else
            dp.push_back(x);
    }
    cout << dp.size() << endl;
    return 0;
}

{% endraw %}
```