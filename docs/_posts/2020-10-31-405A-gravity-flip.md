---
layout: post
mathjax: true
title: 405A Gravity Flip
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
using vi = vector<int>;
int main(void)
{
    int n;
    vi v;
    cin >> n;
    v.resize(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    for (auto x : v)
        cout << x << " ";
    return 0;
}

{% endraw %}
```