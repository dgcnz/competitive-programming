---
layout: post
mathjax: true
title: Abc178_B Product Max
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
using ii = pair<int, int>;
using vi = vector<int>;
int main(void)
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = max({a * c, a * d, b * c, b * d});
    cout << ans << endl;
    return 0;
}

{% endraw %}
```