---
layout: post
mathjax: true
title: 1305A Kuroni And Gifts
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
int a[1010];
int b[1010];
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << endl;
        for (int i = 0; i < n; ++i)
            cout << b[i] << " ";
    }
    return 0;
}

{% endraw %}
```