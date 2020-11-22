---
layout: post
mathjax: true
title: 1322A Unusual Competitions
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
int n;
string s;
int solve(void)
{
    int ans, open_br, l;
    ans = open_br = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
        {
            open_br += 1;
            if (open_br == 0)
                ans += i - l + 1;
        }
        else
        {
            open_br -= 1;
            if (open_br == -1)
                l = i;
        }
    }
    if (open_br != 0)
        return -1;
    return ans;
}
int main(void)
{
    cin >> n >> s;
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```