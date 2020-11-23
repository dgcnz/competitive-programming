---
layout: post
mathjax: true
title: 1362C Johnny Another Rating Drop
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

```cpp
{% raw %}
using namespace std;
using ll = long long;
int main(void)
{
    int t;
    ll n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll ans = 0;
        ll rate = 1;
        for (int i = 0; i < 64; ++i)
        {
            ans += max((ll)0, (ll)((n + 1 + rate - 1) / rate) - 1);
            rate *= 2;
        }
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```