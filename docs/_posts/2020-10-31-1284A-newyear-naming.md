---
layout: post
mathjax: true
title: 1284A Newyear Naming
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
int n, m;
string S[22];
string T[22];
string solve(int year)
{
    string ans;
    ans = S[(year - 1) % n] + T[(year - 1) % m];
    return ans;
}
int main(void)
{
    int q;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
       cin >> S[i];
    for (int i = 0; i < m; ++i)
       cin >> T[i];
    cin >> q;
    while (q--)
    {
        int year;
        cin >> year;
        cout << solve(year) << endl;
    }
    return 0;
}

{% endraw %}
```