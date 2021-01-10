---
layout: post
mathjax: true
title: abc188_c - Abc Tournament
problem_url: https://atcoder.jp/contests/abc188/tasks/abc188_c
tags: implementation, observation, greedy
memory_complexity: O(1)
time_complexity: O(2^n)
---

The two finalist will be the ones that have maximum rating in both halves of
the tournament.


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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    n = (1LL << n);
    ii ansl = {0, 0}, ansr = {0, 0};
    for (int i = 0; i < n / 2; ++i)
    {
        int ai;
        cin >> ai;
        ansl = max(ansl, {ai, i});
    }
    for (int i = n / 2; i < n; ++i)
    {
        int ai;
        cin >> ai;
        ansr = max(ansr, {ai, i});
    }
    ii ans = min(ansl, ansr);
    cout << ans.second + 1 << endl;
    return 0;
}

{% endraw %}
```
</details>

