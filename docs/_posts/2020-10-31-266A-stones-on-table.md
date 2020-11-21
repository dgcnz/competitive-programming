---
layout: post
title: 266A Stones On Table
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
    int n, last, ans = 0;
    string s;
    cin >> n >> s;
    last = 0;
    for (auto c : s)
    {
        if (c == last)
            ++ans;
        last = c;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
