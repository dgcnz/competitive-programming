---
layout: post
mathjax: true
title: 1341A Nastya And Rice
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
using ll = long long;
int main(void)
{
    int t, n, a, b, c, d;
    ll minsum, maxsum;
    bool ans;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b >> c >> d;
        minsum = n * (a - b);
        maxsum = n * (a + b);
        ans = ((minsum) > (c + d)) or (maxsum < (c - d));
        cout << (not ans ? "Yes" : "No") << endl;
    }
    return 0;
}

{% endraw %}
```