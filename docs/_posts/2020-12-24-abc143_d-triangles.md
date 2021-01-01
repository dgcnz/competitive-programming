---
layout: post
mathjax: true
title: abc143_d - Triangles
problem_url: https://atcoder.jp/contests/abc143/tasks/abc143_d
tags: sorting, binary_search
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

If we have the length of the sticks, $l$, sorted non-decreasingly, we can
count all possible triangles by listing two sides $a$, and $b$ and finding
the position, $c$, where the length starts to become degenerate.

Remember that $a + b > c$ and $a \leq b \leq c$.

This can be done with binary search or two-pointers.


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
    vi l(n);
    for (auto &li : l)
        cin >> li;
    sort(begin(l), end(l));
    int ans = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            auto it = lower_bound(begin(l) + j + 1, end(l), l[i] + l[j]);
            int k = distance(begin(l), it);
            if (k - 1 > j)
                ans += k - j - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

