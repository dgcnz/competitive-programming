---
layout: post
mathjax: true
title: abc180_b - Various Distances
problem_url: https://atcoder.jp/contests/abc180/tasks/abc180_b
tags: implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Implementation.


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
using vi = vector<int>;
tuple<ll, double, ll> solve(vi x)
{
    vector<ll> ans(3, 0);
    for (auto xi : x)
    {
        ans[0] += abs(xi);
        ans[1] += ll(xi) * xi;
        ans[2] = max(ans[2], ll(abs(xi)));
    }
    return {ans[0], sqrt(ans[1]), ans[2]};
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi x(n);
    for (auto &xi : x)
        cin >> xi;
    auto [ans0, ans1, ans2] = solve(x);
    cout << ans0 << endl;
    cout << setprecision(12) << fixed << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}

{% endraw %}
```
</details>

