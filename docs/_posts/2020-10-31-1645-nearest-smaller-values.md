---
layout: post
mathjax: true
title: 1645 Nearest Smaller Values
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
using ii = pair<int, int>;
int main(void)
{
    int n, ai;
    stack<ii> S;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ai;
        while (!S.empty() and S.top().first >= ai)
            S.pop();
        if (S.empty())
            cout << "0 ";
        else
            cout << S.top().second + 1 << " ";
        S.push({ai, i});
    }
    return 0;
}

{% endraw %}
```