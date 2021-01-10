---
layout: post
mathjax: true
title: abc188_b - Orthogonality
problem_url: https://atcoder.jp/contests/abc188/tasks/abc188_b
tags: implementation, easy
memory_complexity: O(n)
time_complexity: O(n)
---

Straightforward implementation of dot product.


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
using vi = vector<ll>;
bool solve(vi a, vi b)
{
    vi ans(a.size());
    transform(begin(a), end(a), begin(b), begin(ans), multiplies<ll>());
    return accumulate(begin(ans), end(ans), 0LL) == 0;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n), b(n);
    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;
    cout << (solve(a, b) ? "Yes" : "No") << endl;
    return 0;
}

{% endraw %}
```
</details>

