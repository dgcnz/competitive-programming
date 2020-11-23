---
layout: post
mathjax: true
title: 1367A Short Substrings
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
int main(void)
{
    string b;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> b;
        for (int i = 0; i < (int)b.size(); ++i)
        {
            if (i % 2 == 0)
                cout << b[i];
        }
        cout << b.back() << endl;
    }
    return 0;
}

{% endraw %}
```