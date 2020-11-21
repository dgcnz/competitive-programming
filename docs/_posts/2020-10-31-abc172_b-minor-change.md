---
layout: post
title: Abc172_B Minor Change
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
    int ans = 0;
    string s, t;
    cin >> s >> t;
    for (int i = 0, n = s.size(); i < n; ++i)
    {
        ans += (s[i] != t[i]);
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
