---
layout: post
mathjax: true
title: agc029 - Irreversible Operation
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
int main(void)
{
    string s;
    int wcnt = 0;
    ll ans = 0;
    cin >> s;
    for (int i = (int)s.size() - 1; i >= 0; --i)
    {
        if (s[i] == 'W')
            ++wcnt;
        else
            ans += wcnt;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

