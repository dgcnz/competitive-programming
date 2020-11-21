---
layout: post
title: 101755E Substring Reverse
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
    int n, l = -1, r = -1;
    string s, t;
    cin >> s >> t;
    n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (s[i] != t[i])
        {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] != t[i])
        {
            r = i;
            break;
        }
    }
    if (l != -1 and r != -1)
    {
        for (int i = 0; i < r - l + 1; ++i)
        {
            if (s[l + i] != t[r - i])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}

{% endraw %}
```
