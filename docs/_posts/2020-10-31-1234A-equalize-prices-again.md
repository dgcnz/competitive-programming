---
layout: post
title: 1234A Equalize Prices Again
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
    int t, n, x, s;
    cin >> t;
    while (t--)
    {
        s = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            s += x;
        }
        cout << (int)ceil(s / (n * 1.0)) << endl;
    }
}

{% endraw %}
```
