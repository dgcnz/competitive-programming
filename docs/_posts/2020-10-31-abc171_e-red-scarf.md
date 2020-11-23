---
layout: post
mathjax: true
title: Abc171_E Red Scarf
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
    int n, sum;
    vi a;
    cin >> n;
    sum = 0;
    a.resize(n);
    for (auto &ai : a)
    {
        cin >> ai;
        sum ^= ai;
    }
    for (auto ai : a)
        cout << (ai ^ sum) << " ";
    cout << endl;
    return 0;

{% endraw %}
```