---
layout: post
mathjax: true
title: 1335A Candies Two Sisters
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
using ll = long long;
ll n;
ll solve(void)
{
    ll ans = n - ceil((n + 1) / 2.0);
    if (ans == n - ans)
        return 0;
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```
