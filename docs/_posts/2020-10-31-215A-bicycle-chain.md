---
layout: post
mathjax: true
title: 215A Bicycle Chain
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
    int n, m;
    vi a, b;
    cin >> n;
    a.resize(n);
    for (auto &ai : a)
        cin >> ai;
    cin >> m;
    b.resize(m);
    for (auto &bi : b)
        cin >> bi;
    reverse(b.begin(), b.end());
    multiset<int, greater<int>> ms;
    for (auto bi : b)
    {
        for (auto ai : a)
        {
            if (bi % ai == 0)
            {
                ms.insert(bi / ai);
            }
        }
    }
    cout << ms.count(*ms.begin()) << endl;
    return 0;
}

{% endraw %}
```