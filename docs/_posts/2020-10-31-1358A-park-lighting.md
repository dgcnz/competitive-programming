---
layout: post
title: 1358A Park Lighting
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
    int t, n, m;
    ll ans;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ans = n * (m / 2);
        if (m % 2 == 1)
        {
            if (n % 2 == 0)
                ans += n / 2;
            else
                ans += n / 2 + 1;
        }
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```
