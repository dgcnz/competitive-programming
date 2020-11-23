---
layout: post
mathjax: true
title: 44A Indian Summer
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
map<string, bool> was_already_collected;
int main(void)
{
    int n, counter = 0;
    string tree_kind;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        getline(cin, tree_kind);
        if (not was_already_collected[tree_kind])
            ++counter;
        was_already_collected[tree_kind] = true;
    }
    cout << counter << endl;
    return 0;
}

{% endraw %}
```