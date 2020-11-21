---
layout: post
mathjax: true
title: Abc175_C Walking Takahashi
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

```cpp
{% raw %}
using namespace std;
using ll = long long;
int main(void)
{
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    if (x / d <= k)
    {
        k -= x / d;
        x -= (x / d) * d;
        if (k % 2 == 1)
            x -= d;
    }
    else
    {
        x -= k * d;
        k -= k;
    }
    cout << abs(x) << endl;
    return 0;
}

{% endraw %}
```
