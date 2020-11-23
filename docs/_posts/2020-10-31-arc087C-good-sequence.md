---
layout: post
mathjax: true
title: Arc087C Good Sequence
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
int n;
map<int, int> counter;
int main(void)
{
    int ai, ans = 0, num, times;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        ++counter[ai];
    }
    for (auto num_times : counter)
    {
        num = num_times.first;
        times = num_times.second;
        if (num == times)
            continue;
        while (times != num and times != 0)
        {
            --times;
            ++ans;
        }
    }
    cout << ans << endl;
}

{% endraw %}
```
</details>

