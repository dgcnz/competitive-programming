---
layout: post
mathjax: true
title: 1473C - No More Inversions
problem_url: https://codeforces.com/contest/1473/problem/C
tags: constructive
memory_complexity: O(1)
time_complexity: O(n)
---

This [comment](https://codeforces.com/blog/entry/86743#comment-748158)
explained it well.


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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= 2 * k - n - 1; ++i)
            cout << i << " ";
        for (int i = k; i >= 2 * k - n; --i)
            cout << i << " ";
    }
    return 0;
}

{% endraw %}
```
</details>

