---
layout: post
mathjax: true
title: abc167_a - Registration
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
int main(void)
{
    string s, t;
    cin >> s >> t;
    bool ok = s == t.substr(0, t.size() - 1);
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}

{% endraw %}
```
</details>

