---
layout: post
mathjax: true
title: Abc180_D Takahashi Unevolved
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;
ll iceil(ll a, ll b) { return (a + b - 1) / b; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll xp = 0;
    while (x * a <= x + b and iceil(y, x) > a)
    {
        x *= a;
        xp++;
    }
    ll d = (y - x) % b == 0 ? (y - x - 1) / b : (y - x) / b;
    xp += d;
    cout << xp << endl;
    return 0;
}

{% endraw %}
```
