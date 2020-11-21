---
layout: post
mathjax: true
title: 1305A Kuroni And Gifts
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
int n;
int a[1010];
int b[1010];
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << endl;
        for (int i = 0; i < n; ++i)
            cout << b[i] << " ";
    }
    return 0;
}

{% endraw %}
```
