---
layout: post
mathjax: true
title: 1334A Level Statistics
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
const int NMAX = 100 + 11;
int n, p[NMAX], c[NMAX];
bool solve(void)
{
    int lp, lc, dp, dc;
    lp = lc = 0;
    for (int i = 0; i < n; ++i)
    {
        dp = p[i] - lp;
        dc = c[i] - lc;
        if (dp < 0 or dc < 0 or dp < dc)
            return false;
        lp = p[i];
        lc = c[i];
    }
    return true;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i] >> c[i];
        cout << (solve() ? "YES" : "NO") << endl;
    }
}

{% endraw %}
```