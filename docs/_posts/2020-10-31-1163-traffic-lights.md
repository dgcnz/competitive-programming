---
layout: post
mathjax: true
title: 1163 Traffic Lights
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

```cpp
{% raw %}
using namespace std;
using si = set<int>;
using msi = multiset<int>;
int main(void)
{
    int x, n, point, left, right;
    cin >> x >> n;
    si points = {0, x};
    msi lengths = {x};
    while (n--)
    {
        cin >> point;
        auto it = points.upper_bound(point);
        left = *prev(it);
        right = *it;
        lengths.erase(lengths.find(right - left));
        lengths.insert(point - left);
        lengths.insert(right - point);
        points.insert(it, point);
        cout << *lengths.rbegin() << " ";
    }
    return 0;
}

{% endraw %}
```