---
layout: post
mathjax: true
title: 2216 - Collecting Numbers
problem_url: https://cses.fi/problemset/task/2216
tags: implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Define a mapping (array), $id(a)$ that returns the position of the number
$a$ in the array $x$.

The idea will be to use this mapping to know how many rounds we'll need to
visit all number in an increasing order.

For example, if we start with number $a$ (initially $1$) we can see if  $a+1$
would be visited in the same round if $id(a + 1) > id(a)$.


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
    int n = a.size();
    vi id(n);
    for (int i = 0; i < n; ++i)
        id[a[i] - 1] = i;
    int cur = 0, ans = 0;
    while (cur < n)
    {
        ++cur;
        while (cur < n and id[cur] > id[cur - 1])
            ++cur;
        ++ans;
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << solve(a) << endl;
    return 0;
}

{% endraw %}
```
</details>

