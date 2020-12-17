---
layout: post
mathjax: true
title: abc177_b - Substring
problem_url: https://atcoder.jp/contests/abc177/tasks/abc177_b
tags: brute_force
memory_complexity: O(n)
time_complexity: O(n^2)
---

Try all possible positions for string $T$ and keep the minimum number of
differences for all of them.


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
    string s, t;
    cin >> s >> t;
    int n = (int)(s).size(), m = (int)(t).size(), ans = m;
    for (int i = 0; i <= n - m; ++i)
    {
        int cur = m;
        for (int j = 0; j < m; ++j)
            if (t[j] == s[i + j])
                cur--;
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

