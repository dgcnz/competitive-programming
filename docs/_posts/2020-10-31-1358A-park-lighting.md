---
layout: post
mathjax: true
title: 1358A Park Lighting
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
    int t, n, m;
    ll ans;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ans = n * (m / 2);
        if (m % 2 == 1)
        {
            if (n % 2 == 0)
                ans += n / 2;
            else
                ans += n / 2 + 1;
        }
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```