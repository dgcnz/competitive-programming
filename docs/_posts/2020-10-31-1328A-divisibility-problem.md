---
layout: post
title: 1328A Divisibility Problem
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
    int t, a, b, mod;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        mod = a % b;
        cout << (b - mod) % b << endl;
    }
}

{% endraw %}
```
