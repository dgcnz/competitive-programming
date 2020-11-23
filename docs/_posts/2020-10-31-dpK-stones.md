---
layout: post
mathjax: true
title: Dpk Stones
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
const int NMAX = 1e2 + 11;
const int KMAX = 1e5 + 11;
int n, k, a[NMAX];
bool vis[KMAX], mem[KMAX];
bool wins(int stones)
{
    bool &ans = mem[stones];
    if (vis[stones])
        return ans;
    vis[stones] = true;
    for (int i = 0; i < n; ++i)
        if (stones - a[i] >= 0 and not wins(stones - a[i]))
            return (ans = true);
    return (ans = false);
}
int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << (wins(k) ? "First" : "Second") << endl;
    return 0;
}

{% endraw %}
```
</details>

