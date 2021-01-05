---
layout: post
mathjax: true
title: 1471A - Strange Partition
problem_url: https://codeforces.com/contest/1471/problem/A
tags: greedy
memory_complexity: O(n)
time_complexity: O(n)
---

- Max: Leave the array as it is.
- Min: Merge the array into an element.

Intuitively, by summing the entire array into an element, we reduce the
increasing effect of the ceil function.


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
ll ceil(ll a, ll b) { return (a + b - 1) / b; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (auto &ai : a)
            cin >> ai;
        ll min = ceil(accumulate(begin(a), end(a), 0LL), x);
        ll max = 0;
        for (auto ai : a)
            max += ceil(ai, x);
        cout << min << " " << max << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

