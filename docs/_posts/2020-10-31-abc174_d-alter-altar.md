---
layout: post
mathjax: true
title: Abc174_D Alter Altar
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
int solve(int n, string &s)
{
    int l, r, ans = 0;
    l = 0, r = n - 1;
    while (l < r)
    {
        while (l < n and s[l] != 'W')
            ++l;
        while (r >= 0 and s[r] != 'R')
            --r;
        if (l >= r)
            break;
        swap(s[l], s[r]);
        ++ans;
    }
    return ans;
}
int main(void)
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    cout << solve(n, s) << endl;
    return 0;
}

{% endraw %}
```
</details>

