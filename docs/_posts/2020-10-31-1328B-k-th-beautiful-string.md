---
layout: post
mathjax: true
title: 1328B K Th Beautiful String
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
int binary_search(int low, int high, int target)
{
    auto p = [&](ll x) { return ((x * (x + 1)) / 2) >= (ll)target; };
    while (low < high)
    {
        int mid = low + (high - low + 1) / 2;
        if (p((ll)mid))
            high = mid - 1;
        else
            low = mid;
    }
    if (p((ll)low))
        return 0;
    return low;
}
int main(void)
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll b1, b2;
        b1 = (ll)binary_search(0, n, k) + 1;
        b2 = b1 - (((b1 * (b1 + 1)) / 2) - k) - 1;
        for (int i = 0; i < n; ++i)
        {
            if (i == (n - 1 - b1) or (i == n - 1 - b2))
                cout << 'b';
            else
                cout << 'a';
        }
        cout << endl;
    }
    return 0;
}

{% endraw %}
```
