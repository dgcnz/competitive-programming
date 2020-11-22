---
layout: post
mathjax: true
title: 1399A Remove Smallest
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
using vi = vector<int>;
bool solve(int n, vi a)
{
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i)
    {
        if (a[i] - a[i - 1] > 1)
            return false;
    }
    return true;
}
int main(void)
{
    int t, n;
    vi a;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.assign(n, 0);
        for (auto &ai : a)
            cin >> ai;
        cout << (solve(n, a) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```