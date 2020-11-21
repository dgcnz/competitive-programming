---
layout: post
title: Abc167_B Easy Linear Programming
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
ll solve(int a, int b, int c, int k)
{
    ll ans = 0;
    ans += min(a, k);
    k -= min(a, k);
    if (k == 0)
        return ans;
    k -= min(b, k);
    if (k == 0)
        return ans;
    ans -= min(c, k);
    k -= min(c, k);
    return ans;
}
int main(void)
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << solve(a, b, c, k) << endl;
    return 0;
}

{% endraw %}
```
