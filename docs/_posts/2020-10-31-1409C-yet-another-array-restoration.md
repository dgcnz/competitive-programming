---
layout: post
title: 1409C Yet Another Array Restoration
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
using vi = vector<int>;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        ll bmax = 1e9 + 7, bdiff;
        for (int between = 0; between <= n - 2; ++between)
        {
            if ((y - x) % (between + 1) != 0)
                continue;
            ll diff = (y - x) / (between + 1);
            ll cmin = x, cnt = n - 2 - between;
            while ((cmin - diff) >= 1 and cnt > 0)
            {
                cnt--;
                cmin -= diff;
            }
            ll cmax = cmin + (n - 1) * diff;
            if (cmax < bmax)
            {
                bmax = cmax;
                bdiff = diff;
            }
        }
        for (int i = 0; i < n; ++i)
            cout << bmax - bdiff * i << " ";
        cout << endl;
    }
    return 0;
}

{% endraw %}
```
