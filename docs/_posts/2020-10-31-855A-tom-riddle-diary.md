---
layout: post
mathjax: true
title: 855A Tom Riddle Diary
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

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
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
</details>

