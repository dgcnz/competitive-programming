---
layout: post
mathjax: true
title: abc186_d - Sum Of Difference
problem_url: https://url.com
tags: math, sorting
memory_complexity: O(n)
time_complexity: O(n)
---

Two observations:
- $|x - y| = |y - x|$.
- Each $a_i$ is paired with all other elements $a_j$, $i!=j$.

This allows us to reorder the elements, both in position and in the operand.

Sort the array non-decreasingly. In this way we won't have to worry about
possible negative values:

$$ \sum_{i=n}^{1} (i \times a_i -  \sum_{j = 1}^{i - 1} a_j) $$



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
    vector<ll> a(n), pa(n);
    read_n(begin(a), n);
    sort(begin(a), end(a));
    partial_sum(begin(a), end(a), begin(pa));
    ll ans = 0;
    for (int i = n - 1; i >= 1; --i)
        ans += i * a[i] - pa[i - 1];
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

