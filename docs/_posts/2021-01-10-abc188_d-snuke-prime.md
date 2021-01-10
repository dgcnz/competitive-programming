---
layout: post
mathjax: true
title: abc188_d - Snuke Prime
problem_url: https://atcoder.jp/contests/abc188/tasks/abc188_d
tags: greedy, sweep_line
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Greedily pay for Snuke Prime or not if the accumulated cost of the interval
exceeds the price of a subscription.

To ease implementation, for each interval `[l, r]`, you can merge all `l`'s
with the same value and all `r`'s with the same value. Then apply standard
sweep line to compute the answer.



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
using iii = tuple<int, int, ll>;
using vi = vector<int>;
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll C;
    cin >> n >> C;
    vector<iii> events;
    map<int, ll> A, B;
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        A[a] += c;
        B[b] += c;
    }
    for (auto [k, v] : A)
        events.emplace_back(k, -1, v);
    for (auto [k, v] : B)
        events.emplace_back(k, +1, v);
    sort(begin(events), end(events));
    ll unit_cost = 0, paying_cost = 0, ans = 0;
    int ct = 0;
    for (auto [t, sign, c] : events)
    {
        sign *= -1;
        if (sign == +1)
            ans += (t - ct) * paying_cost;
        else
            ans += (t - ct + 1) * paying_cost;
        unit_cost += sign * c;
        paying_cost = (unit_cost > C ? C : unit_cost);
        ct = (sign == 1 ? t : t + 1);
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

