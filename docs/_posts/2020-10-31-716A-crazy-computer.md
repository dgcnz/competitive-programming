---
layout: post
mathjax: true
title: 716A Crazy Computer
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

```cpp
{% raw %}
using namespace std;
const int NMAX = 1e5 + 11;
int a[NMAX];
int main(void)
{
    int n, c, ans = 1;
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        ++ans;
        if (a[i] - a[i - 1] > c)
            ans = 1;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
