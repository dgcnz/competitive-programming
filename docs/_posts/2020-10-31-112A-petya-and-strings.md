---
layout: post
mathjax: true
title: 112A Petya And Strings
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
bool is_upper(char c) { return 'A' <= c and c <= 'Z'; }
string lower(string s)
{
    string ans = s;
    for (int i = 0, len = s.size(); i < len; ++i)
        if (is_upper(s[i]))
            ans[i] += ('a' - 'A');
    return ans;
}
int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;
    s1 = lower(s1);
    s2 = lower(s2);
    cout << (s1 == s2 ? 0 : (s1 > s2 ? 1 : -1)) << endl;
    return 0;
}

{% endraw %}
```