---
layout: post
mathjax: true
title: Abc174_B Distance
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
int main(void)
{
    ll n, x, y, ans = 0;
    double d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        double cur_dist = sqrt(x * x + y * y);
        if (cur_dist <= d)
            ans++;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
