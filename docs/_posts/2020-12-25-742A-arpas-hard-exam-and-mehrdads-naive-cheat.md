---
layout: post
mathjax: true
title: 742A - Arpas Hard Exam And Mehrdads Naive Cheat
problem_url: https://codeforces.com/problemset/problem/742/A
tags: easy
memory_complexity: O(1)
time_complexity: O(1)
---

Note that $1378^n \equiv 8^n \mod 10$. Furthermore, for $n >= 1$, you might
notice a pattern with $n$ if you list answers for small numbers. They repeat
with a period of 4, so just hardcode them.


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
    int n, ans[4] = {8, 4, 2, 6};
    cin >> n;
    if (n == 0)
        cout << 1 << endl;
    else
        cout << ans[(n - 1) % 4] << endl;
    return 0;
}

{% endraw %}
```
</details>

