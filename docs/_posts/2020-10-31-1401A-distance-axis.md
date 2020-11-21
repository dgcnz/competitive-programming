---
layout: post
mathjax: true
title: 1401A Distance Axis
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
int solve(int n, int k)
{
    if (n < k)
        return k - n;
    else
        return n % 2 != k % 2;
}
int main(void)
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}

{% endraw %}
```
