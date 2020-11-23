---
layout: post
mathjax: true
title: 1342B Binary Period
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
int n;
string s;
bool is_k1(void)
{
    char start = s[0];
    for (int i = 1; i < n; ++i)
    {
        if (s[i] != start)
            return false;
    }
    return true;
}
void solve(void)
{
    if (is_k1())
    {
        for (int i = 0; i < n; ++i)
            cout << s[i];
        return;
    }
    char last = s[0];
    cout << last;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] != last)
        {
            cout << s[i];
        }
        else
        {
            cout << (last == '0' ? '1' : '0');
            cout << s[i];
            last = s[i];
        }
        last = s[i];
    }
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.size();
        solve();
        cout << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

