---
layout: post
mathjax: true
title: 1367A Short Substrings
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
    string b;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> b;
        for (int i = 0; i < (int)b.size(); ++i)
        {
            if (i % 2 == 0)
                cout << b[i];
        }
        cout << b.back() << endl;
    }
    return 0;
}

{% endraw %}
```
