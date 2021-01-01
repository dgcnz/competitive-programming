---
layout: post
mathjax: true
title: 1466B - Last Minute Enhancements
problem_url: https://codeforces.com/contest/1466/problem/B
tags: greedy
memory_complexity: O(n)
time_complexity: O(n)
---

From start to end, increase element if it has already been encountered before
(remember elements are given in non-decreasing order). Then, count unique elements.


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
int solve(vi a)
{
    int n = (int)(a).size();
    vector<bool> vis(a.back() + 5, false);
    for (int i = 0; i < n; ++i)
    {
        if (vis[a[i]])
            a[i]++;
        vis[a[i]] = true;
    }
    return distance(begin(a), unique(begin(a), end(a)));
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        for (auto &x : a)
            cin >> x;
        cout << solve(a) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

