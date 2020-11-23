---
layout: post
mathjax: true
title: 101755J Parallelograms
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
using vi = vector<int>;
int const AMAX = 2e5 + 11;
int cnt[AMAX];
int main(void)
{
    int n, ai, pairs = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        cnt[ai]++;
        if (cnt[ai] % 2 == 0)
            pairs++;
    }
    cout << pairs / 2 << endl;
    return 0;
}

{% endraw %}
```
</details>

