---
layout: post
mathjax: true
title: Abc180_D Takahashi Unevolved
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
using ll = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;
ll iceil(ll a, ll b) { return (a + b - 1) / b; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll xp = 0;
    while (x * a <= x + b and iceil(y, x) > a)
    {
        x *= a;
        xp++;
    }
    ll d = (y - x) % b == 0 ? (y - x - 1) / b : (y - x) / b;
    xp += d;
    cout << xp << endl;
    return 0;
}

{% endraw %}
```
</details>

