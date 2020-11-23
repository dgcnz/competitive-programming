---
layout: post
mathjax: true
title: 1366A Shovels Swords
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
int solve(int a, int b)
{
    int ans = 0;
    if (a < b)
        swap(a, b);
    int diff = a - b;
    if (diff > b)
        return b;
    a -= 2 * diff;
    b -= diff;
    ans += diff;
    if (a == 0)
        return ans;
    int rem = a % 3;
    int q = a / 3;
    ans += 2 * q + (rem / 2);
    return ans;
}
int main(void)
{
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

