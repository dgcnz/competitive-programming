---
layout: post
mathjax: true
title: Agc002_B Box And Ball
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
int main(void)
{
    int n, m, xi, yi;
    vi red, cnt;
    cin >> n >> m;
    cnt.resize(n, 1), red.resize(n, false);
    red[0] = true;
    for (int i = 0; i < m; ++i)
    {
        cin >> xi >> yi, xi--, yi--;
        red[yi] |= red[xi];
        cnt[xi] -= 1;
        cnt[yi] += 1;
        if (cnt[xi] == 0)
            red[xi] = false;
    }
    cout << accumulate(red.begin(), red.end(), 0) << endl;
    return 0;
}

{% endraw %}
```