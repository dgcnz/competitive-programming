---
layout: post
mathjax: true
title: 1395C Boboniu Bit Operations
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
int n, m;
vi a, b;
bool possible(int mask)
{
    for (auto const &ai : a)
    {
        bool ok = false;
        for (auto const &bi : b)
        {
            if (((ai & bi) | mask) == mask)
            {
                ok = true;
                break;
            }
        }
        if (not ok)
            return false;
    }
    return true;
}
int solve(void)
{
    for (int mask = 0; mask < (1 << 9); ++mask)
    {
        if (possible(mask))
            return mask;
    }
    return (1 << 9) - 1;
}
int main(void)
{
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```
</details>

