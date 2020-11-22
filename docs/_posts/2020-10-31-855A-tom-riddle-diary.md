---
layout: post
mathjax: true
title: 855A Tom Riddle Diary
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
map<string, bool> exists;
int main(void)
{
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (exists[s])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        exists[s] = true;
    }
    return 0;
}

{% endraw %}
```