---
layout: post
title: 1341A Nastya And Rice
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
    int t, n, a, b, c, d;
    ll minsum, maxsum;
    bool ans;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b >> c >> d;
        minsum = n * (a - b);
        maxsum = n * (a + b);
        ans = ((minsum) > (c + d)) or (maxsum < (c - d));
        cout << (not ans ? "Yes" : "No") << endl;
    }
    return 0;
}

{% endraw %}
```
