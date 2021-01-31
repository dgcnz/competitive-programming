---
layout: post
mathjax: true
title: abc182_b - Almost Gcd
problem_url: https://atcoder.jp/contests/abc182/tasks/abc182_b
tags: brute_force, number_theory, implementation
memory_complexity: O(n)
time_complexity: O(a_{max} \times n)
---

Count number of elements divisible by $k$ for each $2 \geq k \geq a_{max}$.


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
    int amax = *max_element(begin(a), end(a));
    ii ans = {0, 0};
    for (int k = 2; k <= amax; ++k)
    {
        int cur = count_if(begin(a), end(a), [k](int ai) { return ai % k == 0; });
        ans = max(ans, {cur, k});
    }
    return ans.second;
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

