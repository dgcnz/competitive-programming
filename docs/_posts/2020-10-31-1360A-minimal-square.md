---
layout: post
title: 1360A Minimal Square
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
int main(void)
{
    int t, a, b, ans;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (2 * a > b)
            ans = 2 * a * 2 * a;
        else
            ans = b * b;
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```
