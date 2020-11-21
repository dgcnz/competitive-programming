---
layout: post
mathjax: true
title: 1068 Weird Algorithm
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
    long long n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        n = (n % 2 == 0 ? n / 2 : 3 * n + 1);
    }
    cout << n;
    return 0;
}

{% endraw %}
```
