---
layout: post
mathjax: true
title: Abc139_B Power Socket
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
using ll = long long;
using vi = vector<int>;
int main(void)
{
    int a, b;
    cin >> a >> b;
    b--;
    a--;
    cout << (a + b - 1) / a << endl;
    return 0;
}

{% endraw %}
```
</details>

