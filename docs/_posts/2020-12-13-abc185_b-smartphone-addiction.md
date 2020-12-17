---
layout: post
mathjax: true
title: abc185_b - Smartphone Addiction
problem_url: https://atcoder.jp/contests/abc185/tasks/abc185_b
tags: implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Simulate the battery through time.


{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
bool solve(ll n, ll t, vector<ii> events)
{
    ll ct = 0, battery = n;
    events.emplace_back(t, t);
    for (auto [a, b] : events)
    {
        battery = max(0LL, battery - (a - ct));
        if (battery == 0)
            return false;
        battery = min(n, battery + b - a);
        ct = b;
    }
    return true;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, t;
    cin >> n >> m >> t;
    vector<ii> events(m);
    for (auto &[a, b] : events)
        cin >> a >> b;
    cout << (solve(n, t, events) ? "Yes" : "No") << endl;
    return 0;
}

{% endraw %}
```
</details>

