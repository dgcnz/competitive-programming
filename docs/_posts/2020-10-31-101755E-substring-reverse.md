---
layout: post
mathjax: true
title: 101755E Substring Reverse
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
    int n, l = -1, r = -1;
    string s, t;
    cin >> s >> t;
    n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (s[i] != t[i])
        {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] != t[i])
        {
            r = i;
            break;
        }
    }
    if (l != -1 and r != -1)
    {
        for (int i = 0; i < r - l + 1; ++i)
        {
            if (s[l + i] != t[r - i])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}

{% endraw %}
```