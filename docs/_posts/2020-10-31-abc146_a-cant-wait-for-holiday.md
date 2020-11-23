---
layout: post
mathjax: true
title: Abc146_A Cant Wait For Holiday
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
vector<string> days = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main(void)
{
    string s;
    cin >> s;
    int n = days.size();
    int pos = distance(days.begin(), find(days.begin(), days.end(), s));
    cout << n - pos << endl;
    return 0;
}

{% endraw %}
```
</details>

