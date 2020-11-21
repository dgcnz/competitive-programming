---
layout: post
title: 1409A Yet Another Two Integers
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll diff = abs(b - a);
        ll ans = diff / 10 + ((diff % 10) > 0);
        cout << ans << endl;
    }
    return 0;
}

```
