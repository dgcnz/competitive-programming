---
layout: post
title: 1630 Tasks Deadlines
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
using pll = pair<ll, ll>;
using vpll = vector<pll>;
int main(void)
{
    ll n;
    cin >> n;
    vpll tasks(n);
    for (auto &[a, d] : tasks)
        cin >> a >> d;
    sort(tasks.begin(), tasks.end());
    ll tim = 0, reward = 0;
    for (auto [a, d] : tasks)
    {
        tim += a;
        reward += d - tim;
    }
    cout << reward << endl;
    return 0;
}

{% endraw %}
```
