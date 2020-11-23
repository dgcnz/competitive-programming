---
layout: post
mathjax: true
title: 1418A Buying Torches
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
using ii = pair<int, int>;
using vi = vector<int>;
inline ll ceil(ll a, ll b) { return (a + b - 1) / b; }
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        ll op1 = ceil(k * (y + 1) - 1, x - 1);
        ll op2 = k;
        cout << op1 + op2 << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

