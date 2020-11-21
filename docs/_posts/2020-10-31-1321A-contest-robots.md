---
layout: post
title: 1321A Contest Robots
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
bool r[110];
bool b[110];
int n;
int main(void)
{
    int win = 0, loss = 0, ans;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> r[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
    {
        if (r[i] and not b[i])
            ++win;
        if (not r[i] and b[i])
            ++loss;
    }
    if (win > 0)
        ans = (int)ceil((loss + 1.0) / win);
    else
        ans = -1;
    cout << ans << endl;
}

{% endraw %}
```
