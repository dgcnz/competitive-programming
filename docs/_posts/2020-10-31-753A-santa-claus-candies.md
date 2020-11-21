---
layout: post
mathjax: true
title: 753A Santa Claus Candies
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
    int n, i;
    int sum = 0;
    cin >> n;
    for (i = 1; sum + i <= n and (n - sum - i) > i; ++i)
        sum += i;
    cout << i - 1 + (sum != n) << endl;
    for (int j = 1; j < i; ++j)
        cout << j << " ";
    if (sum != n)
        cout << n - sum << endl;
    return 0;
}

{% endraw %}
```
