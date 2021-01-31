---
layout: post
mathjax: true
title: abc179_a - Plural Form
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
using ii = pair<int, int>;
using vi = vector<int>;
int main(void)
{
    string s;
    cin >> s;
    if (s.back() == 's')
        cout << s << "es" << endl;
    else
        cout << s << "s" << endl;
    return 0;
}

{% endraw %}
```
</details>

