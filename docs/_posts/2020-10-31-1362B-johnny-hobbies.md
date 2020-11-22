---
layout: post
mathjax: true
title: 1362B Johnny Hobbies
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
const int NMAX = 1024 + 11;
int n, s[NMAX];
int solve(void)
{
    sort(s, s + n);
    for (int k = 1; k < NMAX; ++k)
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (binary_search(s, s + n, s[i] ^ k))
                ++cnt;
        if (cnt == n)
            return k;
    }
    return -1;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```