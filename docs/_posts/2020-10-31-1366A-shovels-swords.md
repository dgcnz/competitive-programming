---
layout: post
title: 1366A Shovels Swords
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
int solve(int a, int b)
{
    int ans = 0;
    if (a < b)
        swap(a, b);
    int diff = a - b;
    if (diff > b)
        return b;
    a -= 2 * diff;
    b -= diff;
    ans += diff;
    if (a == 0)
        return ans;
    int rem = a % 3;
    int q = a / 3;
    ans += 2 * q + (rem / 2);
    return ans;
}
int main(void)
{
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}

{% endraw %}
```
