---
layout: post
title: Abc178_B Product Max
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
using ii = pair<int, int>;
using vi = vector<int>;
int main(void)
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = max({a * c, a * d, b * c, b * d});
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
