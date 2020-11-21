---
layout: post
mathjax: true
title: 1661 Subarray Sums Ii
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
int main(void)
{
    int n, x, ai;
    ll s = 0, ans = 0;
    map<ll, int> prefix_count;
    cin >> n >> x;
    prefix_count[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        s += ai;
        ans += prefix_count[s - x];
        ++prefix_count[s];
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
