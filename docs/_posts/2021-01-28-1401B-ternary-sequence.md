---
layout: post
mathjax: true
title: 1401B - Ternary Sequence
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
using ll = long long;
using ds = array<array<ll, 3>, 2>;
ll solve(ds s012)
{
    ll ans = 0;
    ll temp = min(s012[0][2], s012[1][1]);
    ans += 2 * temp;
    s012[0][2] -= temp;
    s012[1][1] -= temp;
    if (s012[0][2] > 0)
    {
        temp = min(s012[0][2], s012[1][2]);
        s012[0][2] -= temp;
        s012[1][2] -= temp;
    }
    if (s012[0][2] > 0)
    {
        temp = min(s012[0][2], s012[1][0]);
        s012[0][2] -= temp;
        s012[1][0] -= temp;
    }
    if (s012[1][2] > 0)
    {
        temp = min(s012[1][2], s012[0][0]);
        s012[1][2] -= temp;
        s012[0][0] -= temp;
    }
    if (s012[1][2] > 0)
    {
        temp = min(s012[1][2], s012[0][1]);
        ans -= 2 * temp;
        s012[1][2] -= temp;
        s012[0][1] -= temp;
    }
    return ans;
}
ll solve2(ds s012)
{
    ll a1 = min(s012[0][2], s012[1][1]);
    ll b0 = s012[1][0] + s012[1][1] - a1;
    ll b1 = max(min(s012[0][1] - b0, s012[1][2]), 0LL);
    return 2 * a1 - 2 * b1;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        ds xyz;
        for (int s = 0; s < 2; ++s)
            for (int i = 0; i < 3; ++i)
                cin >> xyz[s][i];
        cout << solve2(xyz) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

