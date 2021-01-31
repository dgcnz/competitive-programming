---
layout: post
mathjax: true
title: 1397A - Juggling Letters
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
using vi = vector<int>;
bool possible(vi cnt, int n)
{
    for (auto freq : cnt)
    {
        if (freq % n != 0)
            return false;
    }
    return true;
}
int main(void)
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vi cnt(26, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            for (auto c : s)
                cnt[c - 'a']++;
        }
        cout << (possible(cnt, n) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

