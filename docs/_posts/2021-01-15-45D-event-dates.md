---
layout: post
mathjax: true
title: 45D - Event Dates
problem_url: https://codeforces.com/contest/45/problem/D
tags: greedy
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

This is a slight modification of the classical greedy interval scheduling.

Sort intervals, $l, r$, based on their maximum ending time, $r$.
We can greedily pick the $ith$ interval's position by the first $j \geq l$
that is free.


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
using iii = tuple<int, int, int>;
using vi = vector<int>;
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<iii> a(n);
    int maxr = 0, i = 0;
    for (auto &[r, l, ix] : a)
    {
        cin >> l >> r;
        ix = i++;
        maxr = max(maxr, r);
    }
    sort(begin(a), end(a));
    vi used(maxr + 1, 0), ans(n);
    for (auto [r, l, i] : a)
    {
        while (used[l])
            l++;
        ans[i] = l;
        used[l] = true;
    }
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```
</details>

