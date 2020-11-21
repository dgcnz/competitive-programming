---
layout: post
mathjax: true
title: 1392A Omkar Password
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
    int t, n, ai;
    cin >> t;
    while (t--)
    {
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; ++i)
        {
            cin >> ai;
            s.insert(ai);
        }
        if (s.size() == 1)
            cout << n << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}

{% endraw %}
```
